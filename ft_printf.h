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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(int c);
int	ft_printf(const char *s, ...);
int	ft_print_str(char *s);
int	ft_print_num(int num);
int	ft_print_unsigned(unsigned int u);
int	ft_print_hexadecimal(unsigned int num, const char c);
int	ft_print_pointer(unsigned long long addr);

#endif
