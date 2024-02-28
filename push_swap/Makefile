NAME = push_swap
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(addprefix $(LIBFT_DIR), libft.h ft_printf.h get_next_line.h)

CHECKER = checker
CHECKER_HEADER = checker.h

SRCS = \
push_swap.c					push_swap1.c			push_swap2.c			push_swap_parse_input.c	push_swap_parse_input1.c\
push_swap_parse_input2.c	push_swap_ops.c			push_swap_ops1.c		push_swap_ops2.c\
push_swap_ops3.c			push_swap_radix_sort.c	push_swap_radix_sort1.c	push_swap_radix_sort2.c\
push_swap_radix_sort3.c		push_swap_radix_sort4.c	push_swap_small_sort.c	push_swap_small_sort1.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

CHECKER_SRCS = \
checker.c\
push_swap2.c	push_swap_parse_input.c	push_swap_parse_input1.c	push_swap_parse_input2.c\
push_swap_ops.c	push_swap_ops1.c		push_swap_ops2.c			push_swap_ops3.c
CHECKER_OBJS = $(patsubst %.c, %.o, $(CHECKER_SRCS))

LIBFT_SRCS = $(addprefix $(LIBFT_DIR), \
ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strrchr.c\
ft_atoi.c       ft_isascii.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c     ft_strtrim.c\
ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c    ft_substr.c\
ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c\
ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c    ft_toupper.c\
ft_printf.c						ft_printf_make_str_cs.c\
ft_printf_make_str_pdux.c		ft_printf_make_str_spec1.c\
ft_printf_make_str_spec2.c		ft_printf_print_format_string.c\
ft_printf_read_spec.c\
get_next_line.c					get_next_line_utils.c)
LIBFT_OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

bonus: $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(CHECKER)
	touch $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADER)
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
	rm -f $(CHECKER)
	rm -f bonus

re: fclean all

.PHONY: all clean fclean re
