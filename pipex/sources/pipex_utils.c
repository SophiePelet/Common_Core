/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:34:57 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/09 17:21:07 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_infile(const char *infile)
{
	int	exist;
	int	fd;

	exist = access(infile, F_OK | R_OK);
	if (exist == -1)
	{
		ft_putstr_fd(ERR_PERMISSION, 2);
		exit(1);
	}
	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(ERR_FILE_OPEN, 2);
		exit(2);
	}
	return (fd);
}

int	get_outfile(const char *outfile)
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
			ft_putstr_fd(ERR_PERMISSION, 2);
			exit(1);
		}
	}
	fd = open(outfile, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		ft_putstr_fd(ERR_FILE_OPEN, 2);
		exit(2);
	}
	return (fd);
}

void	child_1(int fd1, char *cmd1, int pipe_write)
{
	int	duplicate;

	duplicate = dup2(fd1, STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(4);
	}
	close(fd1);
	duplicate = dup2(pipe_write, STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(4);
	}
	close(pipe_write);
	exe_cmd(cmd1, g_env);
}

void	child_2(int fd2, char *cmd2, int pipe_read)
{
	int	duplicate;

	duplicate = dup2(pipe_read, STDIN_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(4);
	}
	close(pipe_read);
	duplicate = dup2(fd2, STDOUT_FILENO);
	if (duplicate == -1)
	{
		ft_putstr_fd(ERR_DUPLICATION, 2);
		exit(4);
	}
	close(fd2);
	exe_cmd(cmd2, g_env);
}

