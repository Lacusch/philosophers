NAME = philo
CC = cc
SRC = src/actions.c \
	src/fork.c \
	src/main.c \
	src/parcing.c \
	src/philos.c \
	src/thread.c \
	src/time.c \
	src/utils.c
CFLAGS = -Wall -Wextra -pthread #-Werror
all: $(NAME)
$(NAME):
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)
clean:
fclean:
	rm -rf $(NAME)
re:	fclean all
t: all
	./$(NAME) 2 200 200 200 5
t2: all
	./$(NAME) 2 200 200 200
tre: re t
tre2: re t2
.PHONY: all clean fclean re t