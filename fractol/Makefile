# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 13:52:46 by alejjime          #+#    #+#              #
#    Updated: 2025/05/03 16:36:04 by alejjime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = fractol.c fractol_utils.c render.c math_functions.c
OBJ = $(SRCS:.c=.o)
LIB = Libft
MLX = minilibx

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) libft mlx
	$(CC) -o $@ $(OBJ) -L$(LIB) -lft -L$(MLX) -lmlx -lXext -lX11 -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft:
	make -C $(LIB)

mlx:
	make -C $(MLX)

clean:
	rm -f $(OBJ)
	make -C $(LIB) clean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)/libft.a

re: fclean all
.PHONY	:	all libft  mlx clean fclean re