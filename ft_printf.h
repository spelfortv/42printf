#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(int character);
int	ft_printf(const char *str, ...);
int	ft_print_str(char *str);
int	ft_print_num(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexadecimal(unsigned int num, const char word);
int	ft_print_pointer(unsigned long long ptr);

#endif
