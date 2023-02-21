/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:42:04 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 19:43:03 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_hexa(unsigned int num, char type)
{
    int count = 0; 

    if (num >= 16)
    {
        count += ft_print_hexa(num / 16, type);
        count += ft_print_hexa(num % 16, type);
    }
    else
    {
        if (num <= 9)
        {
            ft_print_char(num + '0');
            count++;
        }
        else
        {
            if (type == 'x')
            {
                ft_print_char(num - 10 + 'a');
                count++;
            }
            if (type == 'X')
            {
                ft_print_char(num - 10 + 'A');
                count++;
            }
        }
    }
    return count;
}

