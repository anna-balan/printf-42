/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:29 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/16 19:38:22 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int	ft_check_type(va_list arg, char type)
{
	int	char_count;

	char_count = 0;
	if (type == 'c')
		char_count += ft_print_char(va_arg(arg, int));
	else if (type == 's')
		char_count += ft_print_str(va_arg(arg, char *));
	else if (type == '%')
	{
		char_count += ft_print_char('%');
	}
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
	char str[] = "hello";
	char str2[] = "world";
	ft_printf("this is 1  %s and %s",  str, str2);
	return (0);
}*/
void    ft_putchar(int c, int *len)
{
        write(1, &c, 1);
        *len += 1;
}
void    ft_putstr(char *ap, int *len)
{
        int     i;
        i = 0;
        if (!ap)
        {
                write(1, "(null)", 6);
                *len += 6;
        }
        while (ap[i])
        {
                ft_putchar(ap[i], len);
                i++;
        }
}
void	ft_format_check(va_list *ap, int *len, char format)
{
	if (format == 'c')
		ft_putchar(va_arg(*ap, int), len);
	else if (format == 's')
		ft_putstr(va_arg(*ap, char *), len);
	
	else if (format == '%')
		ft_putchar('%', len);
}	

int	ft_printf(const char *placeholder, ...)
{
	int		len;
	int		i;
	va_list	ap;

	len = 0;
	i = 0;
	va_start(ap, placeholder);
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			ft_format_check(&ap, &len, placeholder[i + 1]);
			i++;
		}
		else
			ft_putchar((char)placeholder[i], &len);
		i++;
	}
	va_end(ap);
	return (len);
}

/*int	main(void)
{
	char str[] = "hello";
	char str2[] = "dcdcc";
	ft_printf("this is 1  %s and %s and %s",  str, str2, "aloha");
	return (0);
}*/

