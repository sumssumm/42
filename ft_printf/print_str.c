/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 00:04:08 by suminpar          #+#    #+#             */
/*   Updated: 2023/08/06 17:19:09 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;
	int	res;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		res = print_char(str[i]);
		if (check_error(&res, &len) == -1)
			return (-1);
		i++;
	}
	return (len);
}

int	print_str(char *str)
{
	int	len;

	if (str == 0)
	{
		len = ft_putstr("(null)");
		return (len);
	}
	len = ft_putstr(str);
	if (len == -1)
		return (-1);
	return (len);
}
