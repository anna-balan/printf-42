/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esotska <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:54:15 by esotska           #+#    #+#             */
/*   Updated: 2023/02/24 12:54:37 by esotska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	counter;

	counter = 0;
	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		counter += 5;
	}
	else
	{
		counter += ft_putstr("0x");
		counter += ft_convert_to_hexa((unsigned long)ptr, 'x');
	}
	return (counter);
}
