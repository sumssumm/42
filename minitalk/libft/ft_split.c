/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:32:56 by suminpar          #+#    #+#             */
/*   Updated: 2023/03/29 23:39:45 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *str, char charset)
{
	int	i;
	int	flag;
	int	words;

	i = 0;
	flag = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != charset && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (str[i] == charset)
			flag = 0;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, char const *src, char charset)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != charset)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

static char	free_str(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
	return (0);
}

static int	do_split(char **result, const char *str, char charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		j = 1;
		if (str[i] != charset)
		{
			while (str[i + j] && str[i + j] != charset)
				j++;
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!result[word])
			{
				free_str(result, word);
				return (0);
			}
			write_word(result[word++], str + i, charset);
		}
		i += j;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!do_split(result, s, c))
		return (NULL);
	return (result);
}
