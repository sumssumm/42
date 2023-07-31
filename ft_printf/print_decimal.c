/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 03:57:38 by suminpar          #+#    #+#             */
/*   Updated: 2023/07/31 11:58:24 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	int			len;
	int			res;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		res = print_char('-');
		if (check_error(&res, &len) == -1)
			return (-1);
	}
	if (n >= 10)
	{
		res = ft_putnbr(n / 10);
		if (check_error(&res, &len) == -1)
			return (-1);
		res = ft_putnbr(n % 10);
		if (check_error(&res, &len) == -1)
			return (-1);
	}
	else
	{
		res = print_char(n + '0');
		if (check_error(&res, &len) == -1)
			return (-1);
	}
	return (len);
}

int	print_decimal(int nbr)
{
	int			len;
	long long	n;	

	n = nbr;
	len = ft_putnbr(n);
	return (len);
}
