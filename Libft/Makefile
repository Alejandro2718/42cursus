NAME = libft.a

SRCS = ft_atoi.c ft_isdigit.c ft_memset.c ft_strncmp.c ft_bzero.c ft_isprint.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_memchr.c ft_strdup.c ft_strrchr.c ft_isalnum.c ft_memcmp.c ft_strlcat.c ft_tolower.c ft_isalpha.c ft_memcpy.c ft_strlcpy.c ft_toupper.c ft_isascii.c ft_memmove.c ft_strlen.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c

OBJS = $(SRCS:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.cc
	$(cc) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all