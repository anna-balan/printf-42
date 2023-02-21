/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:29 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 16:59:00 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}


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

int ft_putnbr_unsigned(unsigned int x) {
     int digits = 0;

    if (x >= 10) {
       digits += ft_putnbr_unsigned(x / 10);
    }

    ft_print_char(x % 10 + '0');
    digits++;

    return digits;
}



int	ft_check_type(va_list *arg, char type, int char_count)
{

	if (type == 'c')
		char_count += ft_print_char(va_arg(*arg, int));
	else if (type == 's')
		char_count += ft_print_str(va_arg(*arg, char *));
	else if (type == 'd' || type == 'i')
		char_count += ft_putnbr(va_arg(*arg, int));
	else if (type == 'u')
		char_count += ft_putnbr_unsigned(va_arg(*arg, unsigned int));
	else if (type == '%')
		char_count += ft_print_char('%');
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char_count = ft_check_type(&arg, format[i + 1], char_count);
			i++;
		}
		else
			char_count += ft_print_char(format[i]);
		i++;

	}
	va_end(arg);
	return (char_count);
}

// int	main(void)
// {
// 	// char str[] = "hello";
// 	// char str2[] = "world";
// 	// ft_printf("this is 1  %s and %s and %s",  str, str2, "more");
// 	// ft_printf("\nChars %c and %c and %c",  'a', 'b', 'c');
// 	// printf("%d", ft_printf("\n%%"));
// 	// printf("%d",ft_printf("this is a %s", "test"));
// 	//ft_printf("%d", 10);
// 	//printf("%d ddndndn\n", ft_putnbr(12));
// 	//ft_printf("%d %i", 2147483647, 7878);
// 	//printf("%s counter %d", "\n", ft_putnbr(-2147483648));
// 	//ft_putnbr(-2147483647);
//  	//ft_printf("%d%d%d%d", 10, 20, 30, 5);

//  	 //ft_printf("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);
//  	  ft_printf("%u to\n %u and %u", 2, 32, (unsigned int)4294967295);
// 	return (0);
// }
/*void    ft_putchar(int c, int *len)
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
}*/
/*int ft_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        ft_putchar(s[i]);
        i++;
    }
}

int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_written = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                char c = va_arg(args, int);
                ft_putchar(c);
                chars_written++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                if (s == NULL) {
                    s = "(null)";
                }
                int len = ft_strlen(s);
                ft_putstr(s);
                chars_written += len;
            } 
            format++;
        } else {
            ft_putchar(*format);
            chars_written++;
            format++;
        }
    }

    va_end(args);
    return chars_written;
}*/


