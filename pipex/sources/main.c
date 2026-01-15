/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:34:51 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/15 16:48:43 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static void	handle_child1(t_pipex *data, int *pipe_end)
{
	close(pipe_end[0]);
	if (data->fd2 != -1)
		close(data->fd2);
	if (data->fd1 == -1)
	{
		close(pipe_end[1]);
		exit(1);
	}
	child_1(data, data->fd1, data->cmd1, pipe_end[1]);
}

static void	handle_child2(t_pipex *data, int *pipe_end)
{
	close(pipe_end[1]);
	if (data->fd1 != -1)
		close(data->fd1);
	if (data->fd2 == -1)
	{
		close(pipe_end[0]);
		exit(1);
	}
	child_2(data, data->fd2, data->cmd2, pipe_end[0]);
}

static void	wait_children(pid_t first_child, pid_t second_child, int *status)
{
	waitpid(first_child, status, 0);
	waitpid(second_child, status, 0);
}

void	pipex(t_pipex *data)
{
	int		pipe_end[2];
	int		status;
	pid_t	first_child;
	pid_t	second_child;

	if (pipe(pipe_end) == -1)
		return (perror("Pipe"));
	first_child = fork();
	if (first_child == -1)
		return (perror("Fork 1"));
	if (first_child == 0)
		handle_child1(data, pipe_end);
	second_child = fork();
	if (second_child == -1)
		return (perror("Fork 2"));
	if (second_child == 0)
		handle_child2(data, pipe_end);
	close(pipe_end[0]);
	close(pipe_end[1]);
	if (data->fd1 != -1)
		close(data->fd1);
	if (data->fd2 != -1)
		close(data->fd2);
	wait_children(first_child, second_child, &status);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;

	data.env = envp;
	if (ac == 5)
	{
		data.fd1 = get_infile(av[1]);
		data.fd2 = get_outfile(av[4]);
		data.cmd1 = av[2];
		data.cmd2 = av[3];
		pipex(&data);
	}
	return (0);
}
