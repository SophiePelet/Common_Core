/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:35:49 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/22 19:34:58 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

void	cleanup_and_exit(char **av, int exit_code)
{
	if (av)
		ft_free_array(av);
	exit(exit_code);
}

void	clean_array_pipes(t_child *child)
{
	int	i;

	if (child->array_pipes)
	{
		i = 0;
		while (i < child->nb_commands - 1)
		{
			if (child->array_pipes[i])
			{
				close(child->array_pipes[i][0]);
				close(child->array_pipes[i][1]);
				free(child->array_pipes[i]);
			}
			i++;
		}
		free(child->array_pipes);
		child->array_pipes = NULL;
	}
}

void	cleanup_on_error(t_child *child)
{
	clean_array_pipes(child);
	if (child->fd_input >= 0)
	{
		close(child->fd_input);
		child->fd_input = -1;
	}
	if (child->fd_output >= 0)
	{
		close(child->fd_output);
		child->fd_output = -1;
	}
	if (child->pid)
	{
		free(child->pid);
		child->pid = NULL;
	}
	if (child->here_doc_pipe)
	{
		free(child->here_doc_pipe);
		child->here_doc_pipe = NULL;
	}
}

void	cleanup_resources(t_child *child)
{
	if (child->fd_input >= 0)
	{
		close(child->fd_input);
		child->fd_input = -1;
	}
	if (child->fd_output >= 0)
	{
		close(child->fd_output);
		child->fd_output = -1;
	}
	if (child->pid)
	{
		free(child->pid);
		child->pid = NULL;
	}
	if (child->here_doc_pipe)
	{
		free(child->here_doc_pipe);
		child->here_doc_pipe = NULL;
	}
}

void	clean_exe_child(t_child *child)
{
	if (child->index_command < child->nb_commands - 1)
		close(child->array_pipes[child->index_command][1]);
	if (child->fd_output > 2)
		close(child->fd_output);
	close_pipes(child);
	free_array_int(child->array_pipes, child->nb_commands - 1);
	free(child->pid);
	free(child->here_doc_pipe);
	exe_cmd(child->cmd[child->index_command], child->env);
}

/* void	populate_struct(int ac, char **av, char **envp, t_child *child_struct)
{
	child_struct->env = envp;
	child_struct->fd_output = get_outfile(av[1], av[ac - 1]);
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
	{
		child_struct->nb_commands = ac - 4;
		child_struct->cmd = &av[3];
	}
	else
	{
		child_struct->nb_commands = ac - 3;
		child_struct->cmd = &av[2];
	}
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
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && av[1][8] == '\0')
		child_struct->fd_input = here_doc(av, child_struct);
	else
		child_struct->fd_input = get_infile(av[1]);
} */