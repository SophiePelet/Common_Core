/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:42:45 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/09 17:21:07 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <fcntl.h>     // for open()
# include <stdio.h>     // for perror()
# include <stdlib.h>    // for exit()
# include <sys/types.h> //for waitpid() and wait()
# include <sys/wait.h>  //for waitpid() and wait()
# include <unistd.h>

# define ERR_CMD_NOT_FOUND "Command not found"
# define ERR_NO_FILE "Not such file or directory"
# define ERR_EXECUTION "Couldn't execute"
# define ERR_PERMISSION "Permission denied"
# define ERR_FILE_OPEN "Couldn't open file"
# define ERR_DUPLICATION "Error while duplicating"

extern char	**g_env;

int		get_infile(const char *infile);
int		get_outfile(const char *outfile);
void	pipex(int fd1, int fd2, char *cmd1, char *cmd2);
const char	*get_cmd_path(char *cmd, char *env[]);
void	child_1(int fd1, char *cmd1, int pipe_write);
void	child_2(int fd2, char *cmd2, int pipe_read);
void	exe_cmd(char *cmd, char *env[]);

#endif
