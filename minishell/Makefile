# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 17:45:08 by alejjime          #+#    #+#              #
#    Updated: 2025/11/29 18:31:29 by adanilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SOURCE = main.c \
		 lexing.c lexing_1.c lexing_2.c lexing_3.c lexing_utils.c lexing_allocation.c lexing_tokenizing.c lexing_tokenizing_1.c \
		 parsing/utils.c parsing/create_cmd_list.c parsing/create_cmd_list_redirections.c parsing/free_utils.c \
		 parsing/parsing.c parsing/errors.c parsing/builtin.c parsing/builtin_utils.c parsing/builtin_utils_1.c parsing/redirections.c parsing/signal_handlers.c parsing/signals.c parsing/execute_cmd.c parsing/heredoc.c
BUILD_DIR = ./build
OBJECTS = $(SOURCE:%.c=$(BUILD_DIR)/%.o)
LIB = libft
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(BUILD_DIR) $(NAME)

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) -o $@ $(OBJECTS) -L$(LIB) -lft -lreadline

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB)/libft.a:
	make -C $(LIB)
	
$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS) $(BUILD_DIR)
	make -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)/libft.a

re: fclean all

.PHONY : all clean fclean re