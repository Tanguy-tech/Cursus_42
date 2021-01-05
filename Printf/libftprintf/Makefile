# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 14:29:24 by tbillon           #+#    #+#              #
#    Updated: 2020/12/22 11:54:48 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c ft_itoa.c ft_bzero.c ft_strlen.c ft_calloc.c ft_isdigit.c\
			ft_strjoin.c ft_strjoin_c.c ft_strjoin_left.c ft_bzero.c\
			ft_strcmp.c ft_strjoin_p.c ft_size_num_base.c

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re