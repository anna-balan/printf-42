/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esotska <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:57:09 by esotska           #+#    #+#             */
/*   Updated: 2023/02/24 12:57:13 by esotska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_convert_to_hexa(unsigned long n, char format)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_convert_to_hexa(n / 16, format);
		counter += ft_convert_to_hexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			counter += ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				counter += ft_putchar(n - 10 + 'a');
			if (format == 'X')
				counter += ft_putchar(n - 10 + 'A');
		}
	}
	return (counter);
}
