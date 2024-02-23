NAME = push_swap
HEADER = push_swap.h

LIBFTPRINTF = $(PRINTF_DIR)libftprintf.a

PRINTF_DIR = ./printf/
PRINTF_HEADER = $(PRINTF_DIR)ft_printf.h

LIBFT_DIR = ./printf/libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
push_swap.c				push_swap_parse_input.c	push_swap_parse_input1.c\
push_swap_ops.c			push_swap_ops1.c		push_swap_ops2.c			push_swap_ops3.c\
push_swap_radix_sort.c	push_swap_radix_sort1.c	push_swap_radix_sort2.c		push_swap_radix_sort3.c\
push_swap_radix_sort4.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_PRINTF = $(addprefix $(PRINTF_DIR), \
ft_printf.c					ft_printf_make_str_cs.c\
ft_printf_make_str_pdux.c	ft_printf_make_str_spec1.c\
ft_printf_make_str_spec2.c	ft_printf_print_format_string.c\
ft_printf_read_spec.c)
OBJS_PRINTF = $(patsubst %.c, %.o, $(SRCS_PRINTF))

SRCS_LIBFT = $(addprefix $(LIBFT_DIR), \
ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strrchr.c\
ft_atoi.c       ft_isascii.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c     ft_strtrim.c\
ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c    ft_substr.c\
ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c\
ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c    ft_toupper.c)
OBJS_LIBFT = $(patsubst %.c, %.o, $(SRCS_LIBFT))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFTPRINTF): $(OBJS_PRINTF) $(LIBFT)
	cp $(LIBFT) $(LIBFTPRINTF)
	ar rcs $(LIBFTPRINTF) $(OBJS_PRINTF)

$(LIBFT): $(OBJS_LIBFT)
	ar rcs $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_PRINTF)
	rm -f $(OBJS_LIBFT)
	rm -f $(LIBFTPRINTF)
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
