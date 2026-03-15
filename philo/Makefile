# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/15 17:57:20 by alejjime          #+#    #+#              #
#    Updated: 2026/03/15 17:57:20 by alejjime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCE = philosopers.c philo_actions.c utils.c
OBJECTS = $(SOURCE:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $(OBJECTS)

%.o: %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re