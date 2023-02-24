/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:50:29 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/24 19:29:49 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list *arg, char type, int char_count)
{
	if (type == 'c')
		char_count += ft_print_char(va_arg(*arg, int));
	else if (type == 's')
		char_count += ft_print_str(va_arg(*arg, char *));
	else if (type == 'p')
		char_count += ft_print_ptr(va_arg(*arg, void *));
	else if (type == 'd' || type == 'i')
		char_count += ft_putnbr(va_arg(*arg, int));
	else if (type == 'u')
		char_count += ft_putnbr_unsigned(va_arg(*arg, unsigned int));
	else if (type == 'x' || type == 'X')
		char_count += ft_print_hexa(va_arg(*arg, unsigned int), type);
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

/*check and fix iteration within loop
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
		printf(" before: %d\n", i);
		if (format[i] == '%')
		{
							printf("format case %d\n", i);
			char_count = ft_check_type(&arg, format[i + 1], char_count);

		}
		else
		{
			char_count += ft_print_char(format[i]);
							printf("Others: %d\n", i);
							
		}
	++i;
	}
	va_end(arg);
	return (char_count);
}
*/
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

//  	 //ft_printf("%u to the power of %u is %u", 2, 32, 4294967295);
//  	  //ft_printf("%u to\n %u and %u", 2, 32, 4294967295);

//  	  char str[] = "hello";
//  	  void *ptr = str;
// 	ft_printf("Pointer address: %p\n", str);

// 	//printf("%d", ft_printf("this is the real number: %X", 256));
// 	return (0);
// }
