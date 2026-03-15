NAME = philo
SOURCE = philosopers.c
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