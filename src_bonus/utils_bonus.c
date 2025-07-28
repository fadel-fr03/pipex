#include "../inc_bonus/pipex_bonus.h"

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

int	open_file(char *file_name, int type)
{
	int	fd;

	if (type == 0)
		fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (type == 1)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == 2)
		fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror(file_name);
		exit(1);
	}
	return (fd);
}
