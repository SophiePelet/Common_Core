/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:42:45 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/15 17:13:15 by sopelet          ###   ########.fr       */
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

# define ERR_CMD_NOT_FOUND "Command not found\n"
# define ERR_EXECUTION "Couldn't execute\n"
# define ERR_DUPLICATION "Error while duplicating\n"
# define ERR_MEM_ALLOCATION "Error while allocating memory\n"
# define READ_END 0
# define WRITE_END 1

typedef struct s_pipex
{
	char	**env;
	int		fd1;
	int		fd2;
	char	*cmd1;
	char	*cmd2;
}			t_pipex;

int			get_infile(const char *infile);
int			get_outfile(const char *outfile);
void		pipex(t_pipex *data);
char		*get_cmd_path(char *cmd, char **env, char **av);
void		child_1(t_pipex *data, int fd1, char *cmd1, int pipe_write);
void		child_2(t_pipex *data, int fd2, char *cmd2, int pipe_read);
void		exe_cmd(char *cmd, char **env);

#endif
