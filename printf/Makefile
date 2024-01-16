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

SRCS_LIBFT = $(addprefix $(LIBFT_DIR), \
ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strrchr.c\
ft_atoi.c       ft_isascii.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c     ft_strtrim.c\
ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c    ft_substr.c\
ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c\
ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c    ft_toupper.c)
OBJS_LIBFT = $(patsubst %.c, %.o, $(SRCS_LIBFT))


all: $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS_BONUS)
	touch $@

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT): $(OBJS_LIBFT)
	ar rcs $@ $^

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	rm -f $(OBJS_LIBFT)
	rm -f $(LIBFT)
	rm -f bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
