# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 19:23:08 by alejjime          #+#    #+#              #
#    Updated: 2025/08/15 17:30:29 by alejjime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SOURCE = push_swap.c node_manipulation.c arguments_checker.c arguments_checker_1.c arguments_checker_2.c operations.c operations_1.c operations_2.c stack_state.c stack_state_1.c costs.c costs_1.c movement.c movement_1.c preparation.c preparation_1.c update_structure.c
OBJECTS = $(SOURCE:.c=.o)
LIB = Libft

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) libft
	$(CC) -o $@ $(OBJECTS) -L$(LIB) -lft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

libft:
	make -C $(LIB)

clean:
	rm -f $(OBJECTS)
	make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)/libft.a

re: fclean all
.PHONY : all clean fclean re