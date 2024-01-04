NAME = libftprintf.a
HEADER = printf.h

LIBFT = ./libft/libft.a
LIBFT_HEADER = ./libft/libft.h
LIBFT_DIR = ./libft/

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

LIBFT_SRCS =\
ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strrchr.c\
ft_atoi.c       ft_isascii.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c     ft_strtrim.c\
ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c    ft_substr.c\
ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c\
ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c    ft_toupper.c
LIBFT_OBJS = $(patsubst %.c, %.o, $(LIBFT_SRCS))


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)

$(LIBFT): $(LIBFT_OBJS) $(LIBFT_HEADER)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
