#include "../inc/libft.h"

static int	number_digits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static long	my_long(int n)
{
	long	num;

	if (n < 0)
		num = -(long)n;
	else
		num = (long)n;
	return (num);
}

/* Use a long to handle case of INT_MIN and INT_MAX*/
char	*ft_itoa(int n)
{
	int		size;
	char	*res;
	long	num;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	size = number_digits(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	num = my_long(n);
	res[size] = '\0';
	while (size--)
	{
		res[size] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
