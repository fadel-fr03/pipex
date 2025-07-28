#include "../inc_bonus/pipex_bonus.h"

void	pipe_error(void)
{
	perror("pipe");
	exit (1);
}

void	fork_error(void)
{
	perror("fork");
	exit (1);
}

void	here_doc_arg_error(void)
{
	ft_putstr_fd("Correct Usage: ./pipex here_doc LIMITER cmd1 cmd2", 1);
	ft_putstr_fd(" ... cmdn file\n", 1);
	exit(1);
}

void	arg_error(void)
{
	ft_putstr_fd("Correct Usage:\n", 1);
	ft_putstr_fd("\t./pipex here_doc LIMITER cmd cmd1 file\n", 1);
	ft_putstr_fd("Or:\n\t./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 1);
	exit (1);
}
