/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:42:04 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/24 19:37:49 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long num, char type)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_print_hexa(num / 16, type);
		count += ft_print_hexa(num % 16, type);
	}
	else
	{
		if (num <= 9)
			count += ft_print_char(num + '0');
		else
		{
			if (type == 'x')
				count += ft_print_char(num - 10 + 'a');
			if (type == 'X')
				count += ft_print_char(num - 10 + 'A');
		}
	}
	return (count);
}
