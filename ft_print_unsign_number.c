/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:55:09 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 20:11:08 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int x)
{
	int	digits;

	digits = 0;
	if (x >= 10)
	{
		digits += ft_putnbr_unsigned(x / 10);
	}
	ft_print_char(x % 10 + '0');
	digits++;
	return (digits);
}
