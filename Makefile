# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: senayat <senayat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 22:45:48 by senayat           #+#    #+#              #
#    Updated: 2024/09/08 09:06:17 by senayat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

SRCS		=	./src/fdf.c					\
				./src/pixelate.c			\
				./src/hooks.c				\
				./src/init_close_win.c		\
				./src/parse_map.c			\
				./src/draw.c				\
				./src/utils.c				\
				./src/camera.c				\
				./src/projection.c

OBJS		=	$(SRCS:.c=.o)

LIB			=	./libft/libft.a

LMX			=	./mlx/libmlx_Linux.a

CC			=	cc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
X11_FLAGS	=	-lX11 -lXext -lm

NAME		=	fdf

all:		$(NAME)

%.o:		%.c
			@printf "Making object files\n"
			$(CC) -c $< -o $@ $(CFLAGS) $(X11_FLAGS)

lib:
			@printf "Making libs\n"
			@$(MAKE) -s -C ./libft
			@$(MAKE) -s -C ./mlx

$(NAME):	$(OBJS) lib
			@printf "Compiling program\n"
			@${CC} ${CFLAGS} ${OBJS} $(LIB) $(LMX) -o ${NAME} $(X11_FLAGS)

clean:
			@$(MAKE) clean -C ./libft
			@$(RM) ./mlx/*.o
			@$(RM) $(OBJS)

fclean:		clean
			@$(MAKE) fclean -C ./libft
			@$(RM) ./mlx/*.a
			@$(RM) $(NAME)

re:			fclean	all

.PHONY:		all	clean	fclean	re
