NAME = push_swap
HEADER = push_swap.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CHECKER = checker
CHECKER_SRCS = \
checker.c\
push_swap1.c				push_swap2.c			push_swap_parse_input.c		push_swap_parse_input1.c\
push_swap_parse_input2.c	push_swap_ops.c			push_swap_ops1.c			push_swap_ops2.c\
push_swap_ops3.c			push_swap_radix_sort.c	push_swap_radix_sort1.c		push_swap_radix_sort2.c\
push_swap_radix_sort3.c		push_swap_radix_sort4.c	push_swap_small_sort.c		push_swap_small_sort1.c
# checker.c					push_swap1.c	push_swap2.c		push_swap_parse_input.c	push_swap_parse_input1.c\
# push_swap_parse_input2.c	push_swap_ops.c	push_swap_ops1.c	push_swap_ops2.c		push_swap_ops3.c
CHECKER_OBJS = $(patsubst %.c, %.o, $(CHECKER_SRCS))
CHECKER_HEADER = checker.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
push_swap.c					push_swap1.c			push_swap2.c				push_swap_parse_input.c		push_swap_parse_input1.c\
push_swap_parse_input2.c	push_swap_ops.c			push_swap_ops1.c			push_swap_ops2.c\
push_swap_ops3.c			push_swap_radix_sort.c	push_swap_radix_sort1.c		push_swap_radix_sort2.c\
push_swap_radix_sort3.c		push_swap_radix_sort4.c	push_swap_small_sort.c		push_swap_small_sort1.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

bonus: $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address $^ -o $(CHECKER)
	touch $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER) $(CHECKER_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_PRINTF)
	rm -f $(CHECKER_OBJS)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
