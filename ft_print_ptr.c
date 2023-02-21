/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:28:03 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 19:50:16 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_print_char((nb + '0'));
		else
			ft_print_char((nb - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long int ptr)
{
	int	char_printed;

	char_printed = 0;
	char_printed += write(1, "0x", 2);
	if (ptr == 0)
	{
		char_printed += write(1, "0", 1);

		//solution for Linux
		// write(1, "(nil)", 5);
		// return (5);
	}
	else
	{
		ft_put_ptr(ptr);
		char_printed += ft_ptr_len(ptr);
	}
	return (char_printed);
}

