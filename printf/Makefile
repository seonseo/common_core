NAME = libftprintf.a
HEADER = printf.h

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)libft.h
LIBFT_MAKEFILE = $(LIBFT_DIR)makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_printer.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) 
	ar rcs $(LIBFT) $(OBJS)
	mv $(LIBFT) libftprintf.a

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADER) $(LIBFT_MAKEFILE)
	make -C $(LIBFT_DIR)
	make clean -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
