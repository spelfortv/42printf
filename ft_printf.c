#include "ft_printf.h"

int	ft_print_char(int character)
{
	write(1, &character, 1);
	return (1);
}

size_t	arg_filter(char c, va_list argument)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_print_char(va_arg(argument, int));
	else if (c == 's')
		size += ft_print_str(va_arg(argument, char *));
	else if (c == 'p')
		size += ft_print_pointer(va_arg(argument, unsigned long long));
	else if (c == 'd' || c == 'i')
		size += ft_print_num(va_arg(argument, int));
	else if (c == 'u')
		size += ft_print_unsigned(va_arg(argument, unsigned int));
	else if (c == 'x' || c == 'X')
		size += ft_print_hexadecimal(va_arg(argument, unsigned int), c);
	else
		size += ft_print_char(c);
	return (size);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	ssize_t	wbytes;
	size_t	i;

	va_start(args, s);
	i = 0;
	wbytes = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			wbytes += arg_filter(s[i], args);
		} else
			wbytes += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (wbytes);
}
