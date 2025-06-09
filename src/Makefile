NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = array_ops.c binary_push.c greedy_push.c main.c parse_input.c utils_math.c utils_sort.c utils.c

BONUS_SRCS = checker.c array_ops.c get_next_line.c parse_input.c utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
