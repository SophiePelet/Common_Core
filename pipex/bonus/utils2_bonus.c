/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:10:57 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/22 19:34:59 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

int	which_outfile(char *arg, const char *outfile)
{
	int	fd;

	if (ft_strncmp(arg, "here_doc", 9) == 0 && arg[8] == '\0')
		fd = open(outfile, O_CREAT | O_APPEND | O_RDWR, 0644);
	else
		fd = open(outfile, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(outfile);
	}
	return (fd);
}

void	fail_split_clean(t_child *child)
{
	cleanup_on_error(child);
	cleanup_and_exit(NULL, 1);
}

void	check_duplication(t_child *child)
{
	int	duplicate;
	int	dev_null;

	if (child->fd_input != -1)
	{
		duplicate = dup2(child->fd_input, STDIN_FILENO);
		if (duplicate == -1)
			exit(1);
		close(child->fd_input);
	}
	else
	{
		dev_null = open("/dev/null", O_RDONLY);
		if (dev_null != -1)
		{
			dup2(dev_null, STDIN_FILENO);
			close(dev_null);
		}
	}
}

void	free_array_int(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	bad_command_message(char *av)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(ERR_CMD_NOT_FOUND, 2);
}
