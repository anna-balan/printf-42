# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbalan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 19:48:14 by hbalan            #+#    #+#              #
#    Updated: 2023/02/17 14:14:25 by hbalan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS =	ft_printf.c ft_print_char.c\
		ft_print_str.c 
		
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
