/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:47:27 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/23 18:23:14 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc != 5)
		arg_errror();
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (!pid)
		child(argv, fd, envp);
	waitpid(pid, NULL, 0);
	parent(argv, fd, envp);
	return (0);
}
