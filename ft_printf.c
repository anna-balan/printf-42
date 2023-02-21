/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:29 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 18:24:56 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <ctype.h>
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

// int ft_print_hex(unsigned int num, char type) 
// {
//      int count = 0;
//     char hex[16];
//     int i = 0;

//     while (num > 0) {
//         int digit = num % 16;
//         if (digit < 10) {
//             hex[i] = digit + '0';
//         } else {
//             hex[i] = digit - 10 + (type == 'X' ? 'A' : 'a');
//         }
//         num /= 16;
//         i++;
//     }
//     hex[i] = '\0';



//     while (i > 0) {
//         i--;
//         count++;
//         write(1, &hex[i], 1);
//     }

//     return count;
// }
int ft_conv_hexa(unsigned int num, char type)
{
    int count = 0; // initialize the counter variable to 0

    if (num >= 16)
    {
        count += ft_conv_hexa(num / 16, type);
        count += ft_conv_hexa(num % 16, type);
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
    return count; // return the total count of printed characters
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
	else if (type == 'x' || type == 'X')
		char_count += ft_conv_hexa(va_arg(*arg, unsigned int), type);
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

int	main(void)
{
	// char str[] = "hello";
	// char str2[] = "world";
	// ft_printf("this is 1  %s and %s and %s",  str, str2, "more");
	// ft_printf("\nChars %c and %c and %c",  'a', 'b', 'c');
	// printf("%d", ft_printf("\n%%"));
	// printf("%d",ft_printf("this is a %s", "test"));
	//ft_printf("%d", 10);
	//printf("%d ddndndn\n", ft_putnbr(12));
	//ft_printf("%d %i", 2147483647, 7878);
	//printf("%s counter %d", "\n", ft_putnbr(-2147483648));
	//ft_putnbr(-2147483647);
 	//ft_printf("%d%d%d%d", 10, 20, 30, 5);

 	 //ft_printf("%u to the power of %u is %u", 2, 32, (unsigned int)4294967295);
 	  //ft_printf("%u to\n %u and %u", 2, 32, (unsigned int)4294967295);

 	//   char str[] = "hello";
 	//   void *ptr = str;
	// printf("Pointer address: %p\n", ptr);

	printf("%d", ft_printf("this is the real number: %X", 256));
	return (0);
}
