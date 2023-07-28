/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:39:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/07/28 10:08:32 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	// return (1);
// }

// int	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		// write(1, &str[i], 1);
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// 	return (i);
// }

// int	print_char(char c)
// {
// 	ft_putchar(c);
// 	return (1);
// }

// int	print_str(char *str)
// {
// 	int	len;

// 	if (str == 0)
// 	{
// 		len = ft_putstr("(null)");
// 		// return (len);
// 	}
// 	else
// 		len = ft_putstr(str);
// 	return (len);
// }

// int	print_decimal(int nb)
// {
// 	int		len;
// 	char	*str;

// 	str = 

// }

int	check_format(const char c, va_list *ap)
{
	if (c == 'c')
		return (print_char(va_arg(*ap, int)));
	if (c == 's')
		return (print_str(va_arg(*ap, char *)));
	// if (c == 'p')
	// 	return (print_ptr(va_arg(*ap, void *)));
	// if (c == 'd' || c == 'i')
	// 	return (print_decimal(va_arg(*ap, int)));
	// if (c == 'u')
	// 	return (print_unsigned_decimal(va_arg(*ap, unsigned int)));
	// if (c == 'x' || c == 'X')
	// 	return (print_hex(va_arg(*ap, unsigned int)), c);
	// if (c == '%')
	// 	return (print_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list ap;

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


#include <stdio.h>

int main()
{
	int num1 = printf("%c%c", 'c', 'd');
	printf("\n");
	int num2 = ft_printf("%c%c", 'c', 'd');
	printf("\n");
	printf("original : %d\nft : %d", num1, num2);

}