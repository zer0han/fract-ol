# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdalal <rdalal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:57:27 by rdalal            #+#    #+#              #
#    Updated: 2024/10/24 19:56:43 by rdalal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRCS_FRAC	=	error_handling.c fractol.c burning_ship.c\
				mandelbrot.c julia.c  \
				mlx_utils.c palette_handling.c colors_handling.c \
				sierpinski_carpet.c

FRAC_PATH	= srcs/

HEAD	= includes/

SRCS	= $(addprefix $(FRAC_PATH), $(SRCS_FRAC))

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wextra -Wall -Werror

LIBFT_PATH	= libft/
LIBFT_H_PATH	= libft/includes/
LIBFT		=	$(LIBFT_PATH)libft.a

MLX	= mlx_linux

MLXFLAGS	= -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_PATH)

$(NAME):	$(LIBFT) $(OBJS) $(HEAD)
			$(CC) $(CFLAGS) $(OBJS) -L$(MLX) -I$(MLX) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I$(HEAD) -I$(LIBFT_H_PATH) -I$(MLX) -c $< -o $@

clean: libft-clean root-clean

libft-clean:
			$(MAKE) -C $(LIBFT_PATH) clean

root-clean:
		rm -f $(OBJS)

fclean: libft-fclean root-fclean

libft-fclean:
		$(MAKE) -C $(LIBFT_PATH) fclean

root-fclean: root-clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft libft-clean libft-fclean root-clean root-fclean