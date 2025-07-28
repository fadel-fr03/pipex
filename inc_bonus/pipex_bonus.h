/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:49:51 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/23 19:49:51 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"

/*		Free Function		*/
void	free_two_dimensional_array(char **array);

/*		Function to Open File With Correct Flags		*/
int		open_file(char *file_name, int type);

/*		Error Handling		*/
void	pipe_error(void);
void	fork_error(void);
void	here_doc_arg_error(void);
void	arg_error(void);

/*		here_doc Related Functions		*/
char	*read_new_line(int fd);
void	here_doc(char **argv, int argc);

/*		Functions to Execute Commands		*/
char	*my_getenv(const char *var, char **envp);
char	*get_path(const char *cmd, char **envp);
void	exec_command(char *command, char **envp);
void	exec_pipes(char *cmd, char **envp);

#endif