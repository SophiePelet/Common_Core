/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:16:01 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/15 17:32:33 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

int	get_infile(const char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(infile);
	}
	return (fd);
}

int	get_outfile(char *arg, const char *outfile)
{
	int	exist;
	int	fd;
	int	autor;

	exist = access(outfile, F_OK);
	if (exist == 0)
	{
		autor = access(outfile, R_OK);
		if (autor == -1)
		{
			ft_putstr_fd("pipex: ", 2);
			perror(outfile);
			exit(1);
		}
	}
	fd = which_outfile(arg, outfile);
	return (fd);
}

void	first_child(t_child *data)
{
	int	duplicate;

	duplicate = dup2(data->fd_input, STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(data->fd_input);
	duplicate = dup2(data->array_pipes[data->index_command][1], STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(data->array_pipes[data->index_command][1]);
	close(data->fd_output);
	close_pipes(data);
	free_array_int(data->array_pipes, data->nb_commands - 1);
	free(data->pid);
	free(data->here_doc_pipe);
	exe_cmd(data->cmd[data->index_command], data->env);
}

void	middle_child(t_child *data)
{
	int	duplicate;

	duplicate = dup2(data->array_pipes[data->index_command - 1][0],
			STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(data->array_pipes[data->index_command - 1][0]);
	duplicate = dup2(data->array_pipes[data->index_command][1], STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(data->array_pipes[data->index_command][1]);
	close(data->fd_output);
	close_pipes(data);
	free_array_int(data->array_pipes, data->nb_commands - 1);
	free(data->pid);
	free(data->here_doc_pipe);
	exe_cmd(data->cmd[data->index_command], data->env);
}

void	last_child(t_child *data)
{
	int	duplicate;

	duplicate = dup2(data->array_pipes[data->index_command - 1][0],
			STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(data->array_pipes[data->index_command - 1][0]);
	duplicate = dup2(data->fd_output, STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(data->fd_output);
	close(data->fd_input);
	close_pipes(data);
	free_array_int(data->array_pipes, data->nb_commands - 1);
	free(data->pid);
	free(data->here_doc_pipe);
	exe_cmd(data->cmd[data->index_command], data->env);
}
