/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:34:51 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/09 17:21:06 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**g_env;

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2)
{
	int		pipe_end[2];
	int		status;
	pid_t	first_child;
	pid_t	second_child;

	if (pipe(pipe_end) == -1)
		return (perror("Pipe"));
	second_child = 0;
	first_child = fork();
	if (first_child == -1)
		return (perror("Fork 1"));
	if (first_child == 0)
	{
		close(pipe_end[0]);
		child_1(fd1, cmd1, pipe_end[1]);
	}
	if (first_child != 0)
	{
		second_child = fork();
		if (second_child == -1)
			return (perror("Fork 2"));
		if (second_child == 0)
		{
			close(pipe_end[1]);
			child_2(fd2, cmd2, pipe_end[0]);
		}
	}
	close(pipe_end[0]);
	close(pipe_end[1]);
	waitpid(first_child, &status, 0);
	waitpid(second_child, &status, 0);
}

int	main(int ac, char **av, char **envp)
{
	int	fd_1;
	int	fd_2;

	g_env = envp;
	if (ac == 5)
	{
		fd_1 = get_infile(av[1]);
		fd_2 = get_outfile(av[4]);
		pipex(fd_1, fd_2, av[2], av[3]);
	}
	return (0);
}
