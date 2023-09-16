/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:39:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/07/31 09:27:41 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char format, va_list *ap)
{
	if (format == 'c')
		return (print_char(va_arg(*ap, int)));
	if (format == 's')
		return (print_str(va_arg(*ap, char *)));
	if (format == 'p')
		return (print_ptr(va_arg(*ap, unsigned long long)));
	if (format == 'd' || format == 'i')
		return (print_decimal(va_arg(*ap, int)));
	if (format == 'u')
		return (print_unsigned_decimal(va_arg(*ap, unsigned int)));
	if (format == 'x' || format == 'X')
		return (print_hex(va_arg(*ap, unsigned int), format));
	if (format == '%')
		return (print_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			len += check_format(format[++i], &ap);
		else
			len += print_char(format[i]);
		if (len < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (len);
}
