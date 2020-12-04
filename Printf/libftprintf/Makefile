# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 14:29:24 by tbillon           #+#    #+#              #
#    Updated: 2020/11/28 14:02:00 by tbillon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strlcat.c ft_strnstr.c \
			ft_tolower.c ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_split.c \
			ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_toupper.c ft_bzero.c ft_isascii.c \
			ft_memccpy.c ft_memmove.c ft_strdup.c  ft_strlen.c ft_strtrim.c ft_calloc.c \
			ft_isdigit.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strncmp.c ft_substr.c \
			ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS   =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= $(SRCS:.c=.o)

OBJSBONUS	= $(BONUS:.c=.o)

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJSBONUS)
			ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re