/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:28:00 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/22 19:34:58 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	execute_child(t_child *child)
{
	if (child->index_command == 0)
		first_child(child);
	else if (child->index_command == child->nb_commands - 1)
		last_child(child);
	else
		middle_child(child);
}

// closes all pipes
void	close_pipes(t_child *child)
{
	int	i;

	i = 0;
	while (i < child->nb_commands - 1)
	{
		close(child->array_pipes[i][0]);
		close(child->array_pipes[i][1]);
		i++;
	}
}

// wait for all children processes to end
void	wait_children(t_child *child)
{
	int	i;
	int	status;

	i = 0;
	while (i < child->nb_commands)
	{
		waitpid(child->pid[i], &status, 0);
		i++;
	}
}

void	populate_struct(int ac, char **av, char **envp, t_child *child_struct)
{
	child_struct->env = envp;
	child_struct->fd_input = get_infile(av[1]);
	child_struct->fd_output = get_outfile(av[1], av[ac - 1]);
	child_struct->nb_commands = ac - 3;
	child_struct->cmd = &av[2];
	child_struct->pid = malloc(sizeof(pid_t) * child_struct->nb_commands);
	if (!child_struct->pid)
	{
		ft_putstr_fd(ERR_MEM_ALLOCATION, 2);
		exit(1);
	}
	child_struct->here_doc_pipe = malloc(sizeof(int) * 2);
	if (!child_struct->here_doc_pipe)
	{
		ft_putstr_fd(ERR_MEM_ALLOCATION, 2);
		exit(1);
	}
	create_pipes(child_struct);
}

void	populate_struct_here_doc(int ac, char **av, char **envp,
		t_child *child_struct)
{
	child_struct->env = envp;
	child_struct->fd_output = get_outfile(av[1], av[ac - 1]);
	child_struct->nb_commands = ac - 4;
	child_struct->cmd = &av[3];
		child_struct->pid = malloc(sizeof(pid_t) * child_struct->nb_commands);
	if (!child_struct->pid)
	{
		ft_putstr_fd(ERR_MEM_ALLOCATION, 2);
		exit(1);
	}
	child_struct->here_doc_pipe = malloc(sizeof(int) * 2);
	if (!child_struct->here_doc_pipe)
	{
		ft_putstr_fd(ERR_MEM_ALLOCATION, 2);
		exit(1);
	}
	create_pipes(child_struct);
	child_struct->fd_input = here_doc(av, child_struct);
}
