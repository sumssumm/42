/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:33:41 by suminpar          #+#    #+#             */
/*   Updated: 2023/03/21 17:45:15 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (needle[0] == '\0')
		return (&((char *)haystack)[i]);
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i + j] == needle[j])
		{
			while (haystack[i + j] && needle[j])
			{
				if (haystack[i + j] != needle[j] || (i + j) >= len)
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
