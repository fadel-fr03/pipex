#include "../inc/libft.h"

static void	stat_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocate;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	allocate = malloc(count * size);
	if (!allocate)
		return (NULL);
	stat_bzero(allocate, count * size);
	return (allocate);
}
