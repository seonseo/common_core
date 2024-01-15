NAME = libftprintf.a
HEADER = ft_printf.h
HEADER_BONUS = ft_printf_bonus.h

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)libft.h
LIBFT_MAKEFILE = $(LIBFT_DIR)makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_printer1.c ft_printf_printer2.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_BONUS = \
ft_printf_bonus.c				ft_printf_print_format_string_bonus.c\
ft_printf_read_spec_bonus.c		ft_printf_make_str_cs_bonus.c\
ft_printf_make_str_pdux_bonus.c	ft_printf_make_str_spec1_bonus.c\
ft_printf_make_str_spec2_bonus.c
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

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)
	rm -f $(LIBFT)
	rm -f bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
