NAME = libftprintf.a
HEADER = printf.h
HEADER_BONUS = printf_bonus.h

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)libft.h
LIBFT_MAKEFILE = $(LIBFT_DIR)makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_printer1.c ft_printf_printer2.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_BONUS = \
ft_printf_bonus.c				ft_printf_format_string_bonus.c	ft_printf_read_spec_bonus.c\
ft_printf_make_str_cs_bonus.c	ft_printf_make_str_pdux_bonus.c	ft_printf_make_str_num_bonus.c\
ft_printf_make_str_bonus.c
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))

all: $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_BONUS)
	touch $@

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADER) $(LIBFT_MAKEFILE)
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f bonus

re: fclean all

.PHONY: all clean fclean re
