/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aide00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:07:38 by abdel-ma          #+#    #+#             */
/*   Updated: 2023/12/21 15:17:32 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_str(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_str("(null)", len);
		return ;
	}
	while (str[i])
	{
		ft_char(str[i], len);
		i++;
	}
}

void	ft_uint(unsigned int n, int *len)
{
	if (n < 10)
	{
		ft_char(n + 48, len);
	}
	else if (n >= 10)
	{
		ft_uint(n / 10, len);
		ft_uint(n % 10, len);
	}
}

void	ft_int(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_str("-2147483648", len);
		return ;
	}
	else if (n < 0)
	{
		ft_char('-', len);
		ft_int(n * (-1), len);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_char(n + 48, len);
	}
	else if (n >= 10)
	{
		ft_int(n / 10, len);
		ft_int(n % 10, len);
	}
}
