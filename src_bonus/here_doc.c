/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:41:49 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/23 23:35:02 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

static int	valid(int c)
{
	return (c != '\0' && c != '\n');
}

char	*read_new_line(int fd)
{
	char	buffer[1024];
	char	*line;
	int		i;
	char	c;
	int		bytes_read;

	i = 0;
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0 && valid(c))
	{
		buffer[i++] = c;
		bytes_read = read(fd, &c, 1);
	}
	if (bytes_read == -1 || (bytes_read == 0 && i == 0))
		return (NULL);
	if (c == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, ft_strlen(buffer) + 1);
	return (line);
}

static void	here_doc_util(int *fd, char **argv)
{
	char	*line;
	size_t	limiter_len;

	limiter_len = ft_strlen(argv[2]);
	while (1)
	{
		line = read_new_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, argv[2], limiter_len) == 0
			&& line[limiter_len] == '\n')
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	exit (0);
}

void	here_doc(char **argv, int argc)
{
	int		fd[2];
	int		pid;

	if (argc < 6)
		here_doc_arg_error();
	if (pipe(fd) == -1)
		pipe_error();
	pid = fork();
	if (pid == -1)
		fork_error();
	if (!pid)
	{
		close(fd[0]);
		here_doc_util(fd, argv);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}
