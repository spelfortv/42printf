#include <stdio.h>
#include <string.h>
#include "ft_printf.h"


size_t	print_int(va_list args)
{
	int	print;

	print = (int)args;
	return (write(1, print, sizeof(int)));
}

size_t	print_char(va_list args)
{
	char	print;

	print = (char)args;
	return (write(1, print, sizeof(char)));
}

size_t	print_str(va_list args)
{
	char	*print;

	print = (char *)args;
	return (write(1, print, ft_strlen(print)));
}

size_t	print_bint(va_list args)
{
	int	print;

	//base conversion...
	print = (char)args;
	return (write(1, print, sizeof(char)));
}

size_t	print_addr(va_list args)
{
	void	*print;

	//revisar
	print = (void *)args;
	return (write(1, &print, sizeof(&void)));
}

size_t	print_uint(va_list args)
{
	unsigned int	print;

	print = (unsigned int)args;
	return (write(1, print, sizeof(unsigned int)));
}

size_t	print_hint(va_list args)
{
	char	print;

	//hacerla (dificil)
	print = (char)args;
	return (write(1, print, sizeof(char)));
}

size_t	print_Hint(va_list args)
{
	char	print;

	//hacerla (dificil)
	print = (char)args;
	return (write(1, print, sizeof(char)));
}

va_list	update_arg(char c, va_list args)
{
	if (c == 'd')
		return (print_int(a_arg(args, int)));
	if (c == 'c')
		return (print_char(va_arg(args, char)));
	if (c == 's')
		return (print_str(a_arg(args, char *)));
	if (c == 'i')
		return (print_bint(va_arg(args, int)));
	if (c == 'p')
		return (print_addr(va_arg(args, void *)));
	if (c == 'u')
		return (print_uint(a_arg(args, unsigned int)));
	if (c == 'x')
		return (print_hint(va_arg(args, unsigned int)));
	if (c == 'X')
		return (print_Hint(va_arg(args, unsigned int)));
	if (c == '%')
		return (print_char(va_arg(args, char)));
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	ssize_t	wbytes;
	char	c;
	size_t	i;

	va_start(args, s);
	i = 0;
	wbytes = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == '%')
		{
			args = update_arg(s[i], args);
			print_args(
		} else
			wbytes += write(1, s[i], 1);
		i++;
	}
	return (wbytes);
}

int main ()
{
	char ch = 'h';

	printf("bwritten:%d", printf("printf:%c|", ch));
	printf("\nbwritten_ft:%d\n\n", ft_printf("ft_printf:|", ch));
	return 0;
}
