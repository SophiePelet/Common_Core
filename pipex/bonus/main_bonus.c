/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:16:12 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/22 15:59:39 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	create_pipes(t_child *child)
{
	int	i;
	int	**array;

	i = 0;
	array = malloc(sizeof(int *) * (child->nb_commands - 1));
	if (!array)
		exit(1);
	while (i < child->nb_commands - 1)
	{
		array[i] = malloc(sizeof(int) * 2);
		if (!array[i])
		{
			free_array_int(array, i);
			ft_putstr_fd(ERR_MEM_ALLOCATION, 2);
			exit(1);
		}
		if (pipe(array[i]) == -1)
		{
			free_array_int(array, i);
			perror("Pipe");
			exit(1);
		}
		i++;
	}
	child->array_pipes = array;
}

static void	pipex_bonus(t_child *child)
{
	int	i;

	i = 0;
	while (i < child->nb_commands)
	{
		child->index_command = i;
		child->pid[i] = fork();
		if (child->pid[i] == -1)
		{
			perror("Fork");
			exit(1);
		}
		if (child->pid[i] == 0)
			execute_child(child);
		i++;
	}
	close_pipes(child);
	wait_children(child);
	free_array_int(child->array_pipes, child->nb_commands - 1);
}

static void	here_doc_pipe(t_child *child)
{
	if (pipe(child->here_doc_pipe) == -1)
	{
		perror("Pipe");
		exit(1);
	}
}

int	here_doc(char **av, t_child *child)
{
	char	*del;
	char	*line;
	size_t	del_len;
	int		fd_pipe;

	here_doc_pipe(child);
	del = av[2];
	del_len = ft_strlen(del);
	fd_pipe = child->here_doc_pipe[WRITE_END];
	ft_putstr_fd("> ", 1);
	line = get_next_line(0, 0);
	while (line != NULL)
	{
		if (ft_strncmp(line, del, del_len) == 0 && line[del_len] == '\n')
			break ;
		ft_putstr_fd("> ", 1);
		ft_putstr_fd(line, fd_pipe);
		free(line);
		line = get_next_line(0, 0);
	}
	get_next_line(0, 1);
	if (line)
		free(line);
	close(fd_pipe);
	return (child->here_doc_pipe[READ_END]);
}

int	main(int ac, char **av, char **envp)
{
	t_child	child;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
			populate_struct_here_doc(ac, av, envp, &child);
		else
			populate_struct(ac, av, envp, &child);
		pipex_bonus(&child);
		cleanup_resources(&child);
	}
}
