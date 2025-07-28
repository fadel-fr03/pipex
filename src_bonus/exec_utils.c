/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:47:22 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/24 11:38:40 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

char	*my_getenv(const char *var, char **envp)
{
	int	len;
	int	i;

	len = ft_strlen(var);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, len) == 0 && envp[i][len] == '=')
			return (&envp[i][len + 1]);
		i++;
	}
	return (NULL);
}

char	*get_path(const char *cmd, char **envp)
{
	char	**all_paths;
	char	*partial_path;
	char	*full_path;
	int		i;

	if (!cmd)
		return (NULL);
	all_paths = ft_split(my_getenv("PATH", envp), ':');
	i = 0;
	while (all_paths[i])
	{
		partial_path = ft_strjoin(all_paths[i], "/");
		full_path = ft_strjoin(partial_path, cmd);
		free(partial_path);
		if (!access(full_path, F_OK | X_OK))
		{
			free_two_dimensional_array(all_paths);
			return (full_path);
		}
		free(full_path);
		++i;
	}
	free_two_dimensional_array(all_paths);
	return (NULL);
}

void	exec_command(char *command, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(command, ' ');
	if (!cmd)
		return ;
	path = get_path(cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_two_dimensional_array(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_two_dimensional_array(cmd);
		perror("execve");
		exit(1);
	}
	free(path);
	free_two_dimensional_array(cmd);
}

void	exec_pipes(char *cmd, char **envp)
{
	int	pid;
	int	fd[2];

	if (pipe(fd))
		pipe_error();
	pid = fork();
	if (pid == -1)
		fork_error();
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		exec_command(cmd, envp);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 0);
}
