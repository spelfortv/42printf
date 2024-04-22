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

static int	ft_length_pointer(unsigned long long address)
{
	int	length;

	length = 0;
	while (address > 0)
	{
		length++;
		address /= 16;
	}
	return (length);
}

static void	ft_search_pointer(unsigned long long address)
{
	if (address >= 16)
	{
		ft_search_pointer(address / 16);
		ft_search_pointer(address % 16);
	}
	else
	{
		if (address < 10)
			ft_print_char(address + '0');
		else
			ft_print_char(address - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		size += write(1, "(nil)", 5);
	else
	{
		size += ft_print_str("0x");
		ft_search_pointer(ptr);
		size += ft_length_pointer(ptr);
	}
	return (size);
}
