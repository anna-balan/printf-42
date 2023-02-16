/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:29 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/15 20:50:32 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list arg, char type)
{
	int	char_count;

	char_count = 0;
	if (type == 'c')
		char_count = ft_print_char(va_arg(arg, int));
	else if (type == 's')
		char_count = ft_print_str(va_arg(arg, char *));

	return (char_count);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	va_start(arg, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			printed_chars += ft_check_type(arg, string[i + 1]);
			i++;
		}
		else
			printed_chars += ft_print_char(string[i]);
		i++;
	}
	va_end(arg);
	return (printed_chars);
}

int	main(void)
{
	ft_printf("%c", 'f');
	return (0);
}