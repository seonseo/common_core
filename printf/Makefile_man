NAME = libftprintf.a
HEADER = printf.h

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)libft.h
LIBFT_MAKEFILE = $(LIBFT_DIR)makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_printer1.c ft_printf_printer2.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADER) $(LIBFT_MAKEFILE)
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
