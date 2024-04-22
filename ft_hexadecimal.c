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

static void	ft_search_hexadecimal(unsigned int n, const char type)
{
	if (n >= 16)
	{
		ft_search_hexadecimal(n / 16, type);
		ft_search_hexadecimal(n % 16, type);
	}
	else
	{
		if (n < 10)
			ft_print_char(n + '0');
		else
		{
			if (type == 'x')
				ft_print_char(n - 10 + 'a');
			if (type == 'X')
				ft_print_char(n - 10 + 'A');
		}
	}
}

static int	ft_length_hexadecimal(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_print_hexadecimal(unsigned int num, const char type)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_search_hexadecimal(num, type);
	return (ft_length_hexadecimal(num));
}
