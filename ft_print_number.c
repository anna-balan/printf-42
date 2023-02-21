/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:54:26 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 19:56:28 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int x) {
    int digits = 0;

    if (x == -2147483648) {
        ft_print_char('-');
        ft_print_char('2');
        x = 147483648;
        digits += 2;
    }
    else if (x < 0) {
        ft_print_char('-');
        x = -x;
        digits++;
    }

    if (x >= 10) {
        digits += ft_putnbr(x / 10);
    }

    ft_print_char(x % 10 + '0');
    digits++;

    return digits;
}