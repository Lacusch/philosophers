NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
DEBUG_FLAG = -Wall -Wextra -pthread -g -fsanitize=address
# Colors
GREEN = \033[1;32m
RED = \033[1;91m
YELLOW = \033[1;33m
NORMAL= \033[0m

SRC = src/actions.c \
	src/check.c \
	src/fork.c \
	src/main.c \
	src/monitoring.c \
	src/parcing.c \
	src/philos.c \
	src/routine.c \
	src/set.c \
	src/thread.c \
	src/time.c \
	src/utils.c

OBJECT = $(SRC:.c=.o)
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

d: fclean $(OBJECT)
	@echo "$(NORMAL)$(GREEN)Making $(NAME)$(NORMAL)"
	@echo "$(NORMAL)$(GREEN)Flags used: $(DEBUG_FLAG)$(NORMAL)"	
	@$(CC) $(OBJECT) $(DEBUG_FLAG) -o $(NAME)
$(NAME): $(OBJECT)
	@echo "$(NORMAL)$(GREEN)Making $(NAME)$(NORMAL)"
	@echo "$(NORMAL)$(GREEN)Flags used: $(CFLAGS)$(NORMAL)"	
	@$(CC) $(OBJECT) $(CFLAGS) -o $(NAME)
	@echo "$(NORMAL)$(NAME) compiled $(NORMAL)"
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

t1: all
	@echo "running test with parameters 1 800 200 200 \n"
	@echo "The philosopher should not eat and should die\n"
	@sleep 1
	@./$(NAME) 1 800 200 200
t2: all
	@echo "running test with parameters5 800 200 200 \n"
	@echo "No philosopher should die\n"
	@sleep 1
	@./$(NAME) 5 800 200 200
t3: all
	@echo "running test with parameters 5 800 200 200 7 \n"
	@echo "No philosopher should die and the simuation should stop after every philo has eaten 7 times"
	@sleep 1
	@./$(NAME) 5 800 200 200 7
t4: all
	@echo "running test with parameters 4 410 200 200 \n"
	@echo "No philosopher should die\n"
	@sleep 1
	@./$(NAME) 4 410 200 200
t5: all
	@echo "running test with parameters 4 310 200 100 \n"
	@echo "One philosopher should die"
	@sleep 1
	@./$(NAME) 4 310 200 100
print:
	@echo "How to add parameters:"
	@echo "./philo \n1.number_of_philosophers\n2.time_to_die\n3.time_to_eat\n4.time_to_sleep\n5.(optional)times to eat\n"
visualiser:
	@echo "Get the visualiser here"
	@echo "https://nafuka11.github.io/philosophers-visualizer/"
.PHONY: all clean fclean re d t t1 t2 t3 t5 t5 print visualiser