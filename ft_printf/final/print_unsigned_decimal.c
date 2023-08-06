/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 07:57:05 by suminpar          #+#    #+#             */
/*   Updated: 2023/08/06 22:40:26 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_decimal(unsigned int nbr)
{
	int	len;
	int	res;

	len = 0;
	if (nbr > 9)
	{
		res = print_unsigned_decimal(nbr / 10);
		if (check_error(res, &len) == -1)
			return (-1);
		res = print_unsigned_decimal(nbr % 10);
		if (check_error(res, &len) == -1)
			return (-1);
	}
	else
	{
		res = print_char(nbr + '0');
		if (check_error(res, &len) == -1)
			return (-1);
	}
	return (len);
}
