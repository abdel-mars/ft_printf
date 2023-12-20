/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aide01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:20:46 by abdel-ma          #+#    #+#             */
/*   Updated: 2023/12/20 22:44:47 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int n, char x, int *len)
{
	char	*hex;

	hex = NULL;
	if (x == 'x')
		hex = "0123456789abcdef";
	else if (x == 'X')
		hex = "0123456789ABCDEF";
	if (n < 16)
		ft_char(hex[n % 16], len);
	if (n >= 16)
	{
		ft_hex(n / 16, x, len);
		ft_char(hex[n % 16], len);
	}
}

void	ft_ptr(unsigned long n, char x, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n < 16)
		ft_char(hex[n % 16], len);
	if (n >= 16)
	{
		ft_ptr(n / 16, x, len);
		ft_char(hex[n % 16], len);
	}
}

void	ft_printadress(unsigned long n, int *len)
{
	if (n == 0)
	{
		ft_str("(nil)", len);
		return ;
	}
	ft_str("0x", len);
	ft_ptr(n, 'x', len);
}

void	ft_check(va_list list, char format, int *len)
{
	if (format == '%')
		ft_char('%', len);
	else if (format == 'c')
		ft_char(va_arg(list, int), len);
	else if (format == 's')
		ft_str(va_arg(list, char *), len);
	else if (format == 'x' || format == 'X')
		ft_hex(va_arg(list, unsigned int), format, len);
	else if (format == 'u')
		ft_uint(va_arg(list, unsigned int), len);
	else if (format == 'i' || format == 'd')
		ft_int(va_arg(list, int), len);
	else if (format == 'p')
	{
		ft_printadress(va_arg(list, unsigned long), len);
	}
}
