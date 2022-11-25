NAME = philo
SRC = src/main.c \
	src/parcing.c \
	src/utils.c
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME):
	cc $(SRC) $(CFLAGS) -o $(NAME)
clean:
fclean:
	rm -rf $(NAME)
re:	fclean all
t: all
	./$(NAME) 2 2 2 2
t2: all
	./$(NAME) 2 2 2 2 2
.PHONY: all clean fclean re t