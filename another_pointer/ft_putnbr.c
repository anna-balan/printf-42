/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esotska <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:49:52 by esotska           #+#    #+#             */
/*   Updated: 2023/02/24 12:49:55 by esotska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count_num;

	count_num = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		count_num += 11;
	}
	else if (nb < 0)
	{
		count_num += ft_putchar('-');
		count_num += ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		count_num += ft_putnbr(nb / 10);
		count_num += ft_putnbr(nb % 10);
	}
	else
	{
		count_num += ft_putchar(nb + '0');
	}
	return (count_num);
}
