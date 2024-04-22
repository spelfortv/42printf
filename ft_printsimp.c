/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spelfort <spelfort@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:09:17 by spelfort          #+#    #+#             */
/*   Updated: 2024/02/14 18:09:24 by spelfort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int num)
{
	int	size;

	size = 0;
	if (num == 0)
		size += ft_print_char('0');
	if (num == -2147483648)
	{
		size += ft_print_str("-2147483648");
		return (size);
	}
	if (num < 0)
	{
		size += ft_print_char('-');
		num = -num;
	}
	if (num > 0)
		size += ft_print_unsigned((unsigned int)num);
	return (size);
}

int	ft_print_str(char *str)
{
	int	size;

	size = 0;
	if (!str)
	{
		return (ft_print_str("(null)"));
	}
	while (*str)
	{
		size += ft_print_char(*str);
		str++;
	}
	return (size);
}

int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_print_char('0');
	else
	{
		if (n / 10 != 0)
			ft_print_unsigned(n / 10);
		ft_print_char((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}
