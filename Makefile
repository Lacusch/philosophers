NAME = philo
SRC = src/main.c
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
	cc $(SRC) $(CFLAGS) -o $(NAME)
$(NAME):

fclean:
	rm -rf $(NAME)
re:	fclean all