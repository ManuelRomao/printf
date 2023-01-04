#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


int	ft_putchar(char	c);
int	ft_putstr(char *str);
int	ft_putperc(void);
int	ft_putnmbr(int	i);
int	ft_va_args(va_list args, const char fmt, int print_len);
int	ft_printf(const char *str, ...);

#endif