/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 00:04:08 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/16 11:44:09 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (write(1, str, i));
}

int	print_str(char *str)
{
	int	len;

	if (str == 0)
		return (print_putstr("(null)"));
	len = print_putstr(str);
	if (len == -1)
		return (-1);
	return (len);
}
