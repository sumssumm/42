/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 07:30:54 by suminpar          #+#    #+#             */
/*   Updated: 2023/08/06 22:39:30 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		check_format(const char format, va_list *ap);

int		print_char(char c);
int		print_str(char *str);
int		print_decimal(int nb);
int		print_unsigned_decimal(unsigned int nbr);
int		print_hex(unsigned int nbr, const char format);
int		print_ptr(unsigned long long ptr);

int		ft_putstr(char *str);
int		ft_putnbr(long long nb);
int		ft_print_addr(unsigned long long ptr);
int		check_error(int res, int *len);

#endif