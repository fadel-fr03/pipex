/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:47:27 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/23 19:55:00 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	in_fd;
	int	out_fd;

	if (argc < 5)
		arg_error();
	if (!ft_strncmp(argv[1], "here_doc", 8) && argv[1][8] == '\0')
	{
		i = 3;
		out_fd = open_file(argv[argc - 1], 0);
		here_doc(argv, argc);
	}
	else
	{
		i = 2;
		out_fd = open_file(argv[argc - 1], 1);
		in_fd = open_file(argv[1], 2);
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	while (i < argc - 2)
		exec_pipes(argv[i++], envp);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	exec_command(argv[i], envp);
}
