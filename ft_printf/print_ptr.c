/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 07:56:18 by suminpar          #+#    #+#             */
/*   Updated: 2023/08/06 18:54:21 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_addr(unsigned long long ptr)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (ptr >= 16)
	{
		len += ft_print_addr(ptr / 16);
		len += ft_print_addr(ptr % 16);
	}
	else
		len += print_char(hex[ptr]);
	return (len);
}

int	print_ptr(unsigned long long ptr)
{
	int	len;
	int	res;

	len = 0;
	res = print_str("0x");
	if (check_error(&res, &len) == -1)
		return (-1);
	res = ft_print_addr(ptr);
	if (check_error(&res, &len) == -1)
		return (-1);
	return (len);
}
