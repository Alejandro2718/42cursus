# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 17:00:09 by alejjime          #+#    #+#              #
#    Updated: 2025/03/09 14:32:29 by alejjime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
LIBRARY = Libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -L$(LIBRARY) -lft

client: client.o libft
	$(CC) -o $@ $< -L$(LIBRARY) -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft:
	make -C $(LIBRARY)

clean:
	rm -f $(OBJECTS)
	make -C $(LIBRARY) clean

fclean: clean
	rm -f server client $(LIBRARY)/libft.a

re: fclean all

.PHONY: all bonus Libft clean fclean re
