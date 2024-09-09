# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: senayat <senayat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 22:45:48 by senayat           #+#    #+#              #
#    Updated: 2024/09/07 11:31:49 by senayat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	src/vector_adddel.c	src/vector_create.c			\
			src/vector_getset.c	src/vector_misc.c			\
			src/vector_calc.c								\
															\
			src/matrix.c									\
															\
			src/ft_isinteger.c		src/ft_isspace.c		\
			src/ft_free_tab.c		src/ft_char_in_str.c	\
			src/ft_atoi.c			src/ft_bzero.c			\
			src/ft_calloc.c			src/ft_isalnum.c		\
			src/ft_isalpha.c		src/ft_isascii.c		\
			src/ft_isdigit.c		src/ft_isprint.c		\
			src/ft_itoa.c			src/ft_lstadd_back.c	\
			src/ft_lstadd_front.c	src/ft_lstclear.c		\
			src/ft_lstdelone.c		src/ft_lstiter.c		\
			src/ft_lstlast.c		src/ft_lstmap.c			\
			src/ft_lstnew.c			src/ft_lstsize.c		\
			src/ft_memccpy.c		src/ft_memchr.c			\
			src/ft_memcmp.c			src/ft_memcpy.c			\
			src/ft_memmove.c		src/ft_memset.c			\
			src/ft_putchar_fd.c		src/ft_putendl_fd.c		\
			src/ft_putnbr_fd.c		src/ft_putstr_fd.c		\
			src/ft_split.c			src/ft_strchr.c			\
			src/ft_strdup.c			src/ft_striteri.c		\
			src/ft_strjoin.c		src/ft_strlcat.c		\
			src/ft_strlcpy.c		src/ft_strlen.c			\
			src/ft_strmapi.c		src/ft_strncmp.c		\
			src/ft_strnstr.c		src/ft_strrchr.c		\
			src/ft_strtrim.c		src/ft_substr.c			\
			src/ft_tolower.c		src/ft_toupper.c		\
			src/ft_extract_line.c	src/ft_strstartswith.c	\
			src/ft_strendswith.c							\
															\
			src/ft_ret.c							\
											\
			src/printf/ft_printf.c	src/printf/ft_puts.c	\
			src/printf/ft_putc.c	src/printf/ft_putp.c	\
			src/printf/ft_putd.c	src/printf/ft_putx.c	\
			src/printf/ft_putu.c							\
															\
			src/get_next_line.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -I.

NAME		=	libft.a


all:		$(NAME)

lib:		all clean

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re

