/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:35:49 by sopelet           #+#    #+#             */
/*   Updated: 2026/02/05 12:34:42 by sopelet          ###   ########.fr       */
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

// clean the child structure
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

// clean up the struct after cmd execution
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
