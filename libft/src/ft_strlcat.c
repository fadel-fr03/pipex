#include "../inc/libft.h"

static size_t	str_len(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	i;
	size_t	j;

	dest_len = str_len(dest);
	src_len = str_len(src);
	total_len = dest_len + src_len;
	i = 0;
	j = dest_len;
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] != '\0' && j < size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (total_len);
}
