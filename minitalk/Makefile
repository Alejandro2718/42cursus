# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 17:00:09 by alejjime          #+#    #+#              #
#    Updated: 2025/03/07 18:53:06 by alejjime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
TARGETS = server client
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Regla principal
all: $(TARGETS)

# Reglas para los ejecutables
server: $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SERVER) -L$(LIBFT_DIR) -lft

client: $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT) -L$(LIBFT_DIR) -lft

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar la biblioteca libft
$(LIBFT):
	make bonus -C $(LIBFT_DIR)

# Limpieza de archivos objeto
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	make -C $(LIBFT_DIR) clean

# Limpieza total
fclean: clean
	rm -f $(TARGETS) $(LIBFT)

# Recompilación total
re: fclean all

.PHONY: all clean fclean re

