#include "../inc/libft.h"

static size_t	number_words(char const *str, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] != c && str[i])
				i++;
			num++;
		}
	}
	return (num);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	stat_free(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

static char	**add(char const *s, char c, char **str, size_t numwords)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < numwords)
	{
		while (s[j] && s[j] == c)
			j++;
		str[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!str[i])
		{
			stat_free(i, str);
			return (NULL);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	words;

	if (!s)
		return (NULL);
	words = number_words(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	str = add(s, c, str, words);
	return (str);
}
