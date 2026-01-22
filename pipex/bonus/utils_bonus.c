/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:16:01 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/22 19:34:59 by sopelet          ###   ########.fr       */
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
			return (-1);
		}
	}
	fd = which_outfile(arg, outfile);
	return (fd);
}

void	first_child(t_child *child)
{
	int	duplicate;

	if (child->fd_input == -1)
	{
		if (child->fd_output > 2)
			close(child->fd_output);
		free(child->here_doc_pipe);
		free(child->pid);
		clean_array_pipes(child);
		exit(1);
	}
	check_duplication(child);
	if (child->fd_input > 2)
		close(child->fd_input);
	duplicate = dup2(child->array_pipes[child->index_command][1], STDOUT_FILENO);
	if (duplicate == -1)
		exit(1);
	clean_exe_child(child);
}

void	middle_child(t_child *child)
{
	int	duplicate;

	duplicate = dup2(child->array_pipes[child->index_command - 1][0],
			STDIN_FILENO);
	if (duplicate == -1)
		exit(1);
	close(child->array_pipes[child->index_command - 1][0]);
	duplicate = dup2(child->array_pipes[child->index_command][1], STDOUT_FILENO);
	if (duplicate == -1)
		exit(1);
	if (child->fd_input != -1)
		close(child->fd_input);
	close(child->array_pipes[child->index_command][1]);
	clean_exe_child(child);
}

void	last_child(t_child *child)
{
	int	duplicate;

	if (child->fd_output == -1)
	{
		if (child->fd_input != -1)
			close(child->fd_input);
		free(child->here_doc_pipe);
		free(child->pid);
		clean_array_pipes(child);
		exit(1);
	}
	duplicate = dup2(child->array_pipes[child->index_command - 1][0],
			STDIN_FILENO);
	if (duplicate == -1)
		exit(1);
	close(child->array_pipes[child->index_command - 1][0]);
	if (child->fd_input > 2)
		close(child->fd_input);
	duplicate = dup2(child->fd_output, STDOUT_FILENO);
	if (duplicate == -1)
		exit(1);
	clean_exe_child(child);
}
