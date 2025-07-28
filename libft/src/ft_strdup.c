/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:17:45 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/21 16:24:35 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*ptr;
	int		i;

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ptr = dest;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ptr);
}
