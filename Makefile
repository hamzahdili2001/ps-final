NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
RM = rm -rf

INCLUDE = includes/push_swap.h
SRC = src/main.c src/bench/benchmark.c  src/bench/output.c \
	  src/parsing/free_normalize.c src/parsing/ft_split.c \
	  src/parsing/normalize_args.c src/parsing/parse_nums.c \
	  src/parsing/ft_atoi.c src/parsing/ft_substr.c  src/parsing/parse_flag.c \
	  src/sort/adaptive_sort.c src/sort/disorder.c src/sort/simple_sort.c \
	  src/sort/sort_utils.c src/sort/complex_sort.c src/sort/medium_sort.c \
	  src/sort/simple_sort_helpers.c src/stack/op.c  src/stack/ops_utils.c \
	  src/stack/ps_init.c src/stack/stack.c src/utils/utils.c src/utils/utils_extra.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
