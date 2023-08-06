/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 07:55:16 by suminpar          #+#    #+#             */
/*   Updated: 2023/08/06 17:18:12 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nbr, const char format)
{
	int				len;
	int				res;
	char			*hex;

	len = 0;
	if (format == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nbr >= 16)
	{
		res = print_hex(nbr / 16, format);
		if (check_error(&res, &len) == -1)
			return (-1);
		res = print_hex(nbr % 16, format);
		if (check_error(&res, &len) == -1)
			return (-1);
	}
	else
	{
		res = print_char(hex[nbr]);
		if (check_error(&res, &len) == -1)
			return (-1);
	}
	return (len);
}
