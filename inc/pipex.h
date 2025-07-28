/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:47:24 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/23 18:17:29 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../libft/inc/libft.h"

/*		Free Function		*/
void	free_two_dimensional_array(char **array);

/*		Error Handling		*/
void	arg_errror(void);

/*		Functions to Execute Commands		*/
char	*my_getenv(const char *var, char **envp);
char	*get_path(const char *cmd, char **envp);
void	exec_command(char *command, char **envp);

/*		Process Execution		*/
void	child(char **argv, int *pipefd, char **envp);
void	parent(char **argv, int *pipe, char **envp);

#endif