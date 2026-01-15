/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:34:57 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/15 17:33:52 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

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

int	get_outfile(const char *outfile)
{
	int	fd;

	fd = open(outfile, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(outfile);
	}
	return (fd);
}

void	child_1(t_pipex *data, int fd1, char *cmd1, int pipe_write)
{
	int	duplicate;

	duplicate = dup2(fd1, STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(fd1);
	duplicate = dup2(pipe_write, STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(pipe_write);
	exe_cmd(cmd1, data->env);
}

void	child_2(t_pipex *data, int fd2, char *cmd2, int pipe_read)
{
	int	duplicate;

	duplicate = dup2(pipe_read, STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(pipe_read);
	duplicate = dup2(fd2, STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(1);
	}
	close(fd2);
	exe_cmd(cmd2, data->env);
}
