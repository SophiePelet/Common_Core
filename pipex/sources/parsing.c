/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:02:43 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/09 17:07:28 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static const char	*test_path(const char *cmd, const char *path)
{
	char	**split;
	char	*join_path;
	char	*cmd_path;
	int		i;

	i = 0;
	if (cmd[0] == '/')
		return (cmd);
	if (!path || !*path) //remove it ?
		return (NULL);
	split = ft_split(path, ':');
	while (split[i])
	{
		join_path = ft_strjoin(split[i], "/");
		if (!join_path)
			return (ft_free_array(split), NULL);
		cmd_path = ft_strjoin(join_path, cmd);
		if (!cmd_path)
			return (ft_free_array(split), NULL);
		free(join_path);
		if (access(cmd_path, X_OK) != -1)
			return (ft_free_array(split), cmd_path);
		free(cmd_path);
		i++;
	}
	ft_free_array(split);
	return (NULL);
}

const char	*get_cmd_path(char *cmd, char *env[])
{
	int		i;
	const char	*cmd_path;

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
		ft_putstr_fd(ERR_CMD_NOT_FOUND, 2);
		exit(127);
	}
	return (cmd_path);
}

void	exe_cmd(char *cmd, char *env[])
{
	const char	*cmd_path;
	char	**av;

	av = ft_split(cmd, ' ');
	if (!av)
		exit(5);
	cmd_path = get_cmd_path(cmd, env);
	execve(cmd_path, av, env);
	ft_putstr_fd(ERR_EXECUTION, 2);
	exit(127);
}
