NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -pthread #-Werror

# Colors
GREEN = \033[1;32m
RED = \033[1;91m
YELLOW = \033[1;33m
NORMAL= \033[0m
SRC = src/actions.c \
	src/eat.c \
	src/fork.c \
	src/main.c \
	src/monitoring.c \
	src/parcing.c \
	src/philos.c \
	src/thread.c \
	src/time.c \
	src/utils.c
OBJECT = $(SRC:.c=.o)
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECT)
	@echo "$(NORMAL)$(GREEN)Making $(NAME)$(NORMAL)"
	@echo "$(NORMAL)$(GREEN)Flags used: $(CFLAGS)$(NORMAL)"	
	@$(CC) $(OBJECT) $(CFLAGS) -o $(NAME)
clean:
	@echo "$(YELLOW)Cleaning *.o files$(NORMAL)"
	@rm -rf src/*.o
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Cleaning $(NAME)$(NORMAL)"
re:	fclean all
t: all
	@echo "running test with parameters 2 200 200 200 5 \n"
	@sleep 1
	@./$(NAME) 2 200 200 200 5
t2: all
	@sleep 1
	@echo "running test with parameters 2 200 200 200 5 \n"
	./$(NAME) 2 200 200 200
t3: all
	@sleep 1
	@echo "running test with parameters 10 1000 200 200 5 \n"
	./$(NAME) 10 1000 200 200 5
t4: all
	@sleep 1
	@echo "running test with parameters 30 600 200 200 5 \n"
	./$(NAME) 10 200 200 200
print:
	@echo "How to add parameters:"
	@echo "./philo n\nnumber_of_philosophers\ntime_to_die\ntime_to_eat\ntime_to_sleep"
.PHONY: all clean fclean re t