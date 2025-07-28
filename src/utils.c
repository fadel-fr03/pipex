/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:47:29 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/23 19:38:40 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child(char **argv, int *pipefd, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	close(pipefd[0]);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd);
	close(pipefd[1]);
	exec_command(argv[2], envp);
}

void	parent(char **argv, int *pipefd, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(argv[4]);
		exit(1);
	}
	close(pipefd[1]);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(fd);
	close(pipefd[0]);
	exec_command(argv[3], envp);
}

void	free_two_dimensional_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	arg_errror(void)
{
	ft_putstr_fd("Correct Usage: ./pipex infile cmd1 cmd2 outfile\n", 1);
	exit(1);
}
