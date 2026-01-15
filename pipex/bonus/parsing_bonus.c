/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:14:06 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/15 17:08:51 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

static char	*absolute_path(const char *cmd)
{
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return ((char *)cmd);
	}
	return (NULL);
}

static char	*test_path(const char *cmd, const char *path)
{
	char	**split;
	char	*join_path;
	char	*cmd_path;
	int		i;

	i = 0;
	absolute_path(cmd);
	split = ft_split(path, ':');
	while (split[i])
	{
		join_path = ft_strjoin(split[i], "/");
		if (!join_path)
			return (ft_free_array(split), NULL);
		cmd_path = ft_strjoin(join_path, cmd);
		if (!cmd_path)
			return (free(join_path), ft_free_array(split), NULL);
		free(join_path);
		if (cmd_path && access(cmd_path, X_OK) == 0)
			return (ft_free_array(split), cmd_path);
		free(cmd_path);
		i++;
	}
	return (ft_free_array(split), NULL);
}

char	*get_cmd_path(char *cmd, char **env, char **av)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	cmd_path = test_path(cmd, env[i] + 5);
	if (!cmd_path)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(ERR_CMD_NOT_FOUND, 2);
		if (av)
			ft_free_array(av);
		exit(127);
	}
	return (cmd_path);
}

void	exe_cmd(char *cmd, char **env)
{
	char	*cmd_path;
	char	**av;

	av = ft_split(cmd, ' ');
	if (!av)
		exit(1);
	cmd_path = get_cmd_path(av[0], env, av);
	execve(cmd_path, av, env);
	ft_putstr_fd("pipex: ", 2);
	perror(av[0]);
	exit(127);
}
