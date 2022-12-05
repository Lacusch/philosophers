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
OBJECT = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -pthread #-Werror
all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) $(CFLAGS) -o $(NAME)
clean:
	rm src/*.o
fclean: clean
	rm -rf $(NAME)
re:	fclean all
t: all
	./$(NAME) 2 200 200 200 5
t2: all
	./$(NAME) 2 200 200 200
.PHONY: all clean fclean re t