/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 00:04:08 by suminpar          #+#    #+#             */
/*   Updated: 2023/07/28 09:39:04 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		// write(1, &str[i], 1);
		ft_putchar(str[i]);
		i++;
	}
	return (i);
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
	return (len);
}