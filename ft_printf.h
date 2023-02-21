/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:51:19 by hbalan            #+#    #+#             */
/*   Updated: 2023/02/21 20:17:02 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		len_ptr(uintptr_t nb);
void	ft_put_ptr(uintptr_t nb);
int		ft_print_ptr(unsigned long int ptr);
int		ft_print_hexa(unsigned int num, char type);
int		ft_putnbr(int x);
int		ft_putnbr_unsigned(unsigned int x);

#endif
