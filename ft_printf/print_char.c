/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:39:45 by suminpar          #+#    #+#             */
/*   Updated: 2023/07/28 10:02:30 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
	// return (1);
}

int	print_char(char c)
{
	// write(1, &c, 1);
	return (ft_putchar(c));
}