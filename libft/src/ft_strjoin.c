/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fal-frou <fadelfr61@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:32:13 by fal-frou          #+#    #+#             */
/*   Updated: 2024/07/21 16:24:35 by fal-frou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	str_len(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (joined);
}
