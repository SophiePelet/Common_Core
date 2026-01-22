/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:37:52 by sopelet           #+#    #+#             */
/*   Updated: 2026/01/22 19:34:57 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "libft.h"
# include <errno.h>
# include <fcntl.h>     // for open()
# include <stdio.h>     // for perror()
# include <stdlib.h>    // for exit()
# include <sys/types.h> //for waitpid() and wait()
# include <sys/wait.h>  //for waitpid() and wait()
# include <unistd.h>
# include <string.h>

# define ERR_CMD_NOT_FOUND "command not found\n"
# define ERR_PATH_NOT_FOUND "No such file or directory\n"
# define ERR_EXECUTION "Couldn't execute\n"
# define ERR_MEM_ALLOCATION "Error while allocating memory\n"
# define READ_END 0
# define WRITE_END 1

typedef struct s_child
{
	int		fd_input;
	int		fd_output;
	int		**array_pipes;
	int		nb_commands;
	pid_t	*pid;
	int		index_command;
	char	**cmd;
	char	**env;
	int		*here_doc_pipe;
}			t_child;

// Helpers
void		create_pipes(t_child *child);
void		execute_child(t_child *child);
void		close_pipes(t_child *child);
void		wait_children(t_child *child);
int			which_outfile(char *arg, const char *outfile);
void		free_array_int(int **array, int size);
void		populate_struct(int ac, char **av, char **envp, t_child *child);
void		populate_struct_here_doc(int ac, char **av, char **envp,
				t_child *child_struct);
void		bad_command_message(char *av);
void		cleanup_and_exit(char **av, int exit_code);
void		fail_split_clean(t_child *child);
void		error_msg(char *prefix, char *msg, char *error_msg);

// Cleaning
void		clean_array_pipes(t_child *child);
void		cleanup_resources(t_child *child);
void		cleanup_on_error(t_child *child);
void		clean_exe_child(t_child *child);

// Get files and execute commands
int			get_infile(const char *infile);
int			get_outfile(char *arg, const char *outfile);
void		first_child(t_child *child);
void		middle_child(t_child *child);
void		last_child(t_child *child);
void		exe_cmd(char *cmd, char **env);
void		validate_cmd(char *cmd, char **env, t_child *child);
int			here_doc(char **av, t_child *child);
void		check_duplication(t_child *child);

#endif