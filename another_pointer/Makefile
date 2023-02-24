# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esotska <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 12:43:43 by esotska           #+#    #+#              #
#    Updated: 2023/02/24 12:43:47 by esotska          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_convert_to_hexa.c ft_putnbr.c ft_putptr.c \
		ft_putnbr_unsigned.c ft_putchar.c ft_putstr.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
INCS = ft_printf.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}
		
${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re

