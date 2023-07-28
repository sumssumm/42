#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		print_char(char c);
int		print_str(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_printf(const char *format, ...);






#endif