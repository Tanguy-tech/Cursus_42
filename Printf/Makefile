# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 10:11:35 by tbillon           #+#    #+#              #
#    Updated: 2020/12/10 16:43:32 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_width.c ft_width_utils.c ft_parsing.c ft_converter.c\
			libftprintf/ft_itoa.c libftprintf/ft_itoa_base.c ft_precision.c \
			libftprintf/ft_putchar.c libftprintf/ft_putstr.c ft_justify.c \
			libftprintf/ft_strlen.c libftprintf/ft_strjoin.c \
			ft_converter_utils.c libftprintf/ft_atoi.c libftprintf/ft_isdigit.c \
			libftprintf/ft_size_num.c libftprintf/ft_abs.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

rsu	fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re