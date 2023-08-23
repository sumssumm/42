/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:44:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/03/20 20:14:13 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	src_len = 0;
	while (*dst)
		dst++;
	while (*src && dst_len + src_len + 1 < dstsize)
	{
		*dst++ = *src++;
		src_len++;
	}
	while (*src)
	{
		src++;
		src_len++;
	}
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	*dst = '\0';
	return (dst_len + src_len);
}
