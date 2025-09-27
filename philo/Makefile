# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/27 18:15:37 by alejjime          #+#    #+#              #
#    Updated: 2025/09/27 20:54:32 by alejjime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCE = philo.c ft_atoi.c
OBJECTS = $(SOURCE:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY : all clean fclean re