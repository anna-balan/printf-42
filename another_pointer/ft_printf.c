/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esotska <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:46:32 by esotska           #+#    #+#             */
/*   Updated: 2023/02/22 11:48:05 by esotska          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_arg_type(va_list *arg, char ch_type, int char_len)
{
	if (ch_type == 'c')
		char_len += ft_putchar(va_arg(*arg, int));
	else if (ch_type == 's')
		char_len += ft_putstr(va_arg(*arg, char *));
	else if (ch_type == 'd' || ch_type == 'i')
		char_len += ft_putnbr(va_arg(*arg, int));
	else if (ch_type == 'u')
		char_len += ft_putnbr_unsigned(va_arg(*arg, unsigned int));
	else if (ch_type == 'x' || ch_type == 'X')
		char_len += ft_convert_to_hexa(va_arg(*arg, unsigned int), ch_type);
	else if (ch_type == '%')
		char_len += ft_putchar('%');
	else if (ch_type == 'p')
		char_len += ft_putptr(va_arg(*arg, void *));
	return (char_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		num_char;

	i = 0;
	num_char = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			num_char = ft_arg_type(&arg, format[i + 1], num_char);
			i++;
		}
		else
			num_char += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (num_char);
}

/*int main() 
{
    int c = 'A';
    int n = 10;
    char str[] = "Hello World";
    unsigned int	i = 435;
    int ptr = 42;
    printf("%c", c);
    printf("\n");
    ft_printf("%c", c);
    printf("\n");
    printf("%s", str);
    printf("\n");
    ft_printf("%s", str);
    printf("\n");
    printf("%d", n);
    printf("\n");
    ft_printf("%d", n);
    printf("\n");
    ft_printf("%u", i);
    printf("\n");
    printf("%u", i);
     printf("\n");
    printf("%x %X", i, i);
    printf("\n");
    ft_printf("%x %X", i, i);
    printf("\n");
    printf("pointer value: %p\n", &ptr);
    printf("\n");
    ft_printf("pointer value: %p\n", &ptr);
    return 0;
}
*/
