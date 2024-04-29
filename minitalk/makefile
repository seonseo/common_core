NAME = client server
HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h

CC = cc
# CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
OBJ_CLIENT = $(patsubst %.c, %.o, $(SRC_CLIENT))

SRC_SERVER = server.c
OBJ_SERVER = $(patsubst %.c, %.o, $(SRC_SERVER))

SRC_CLIENT_BONUS = client_bonus.c
OBJ_CLIENT_BONUS = $(patsubst %.c, %.o, $(SRC_CLIENT_BONUS))

SRC_SERVER_BONUS = server_bonus.c
OBJ_SERVER_BONUS = $(patsubst %.c, %.o, $(SRC_SERVER_BONUS))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(addprefix $(LIBFT_DIR), libft.h ft_printf.h get_next_line.h)
LIBFT_FLAGS = -Llibft -lft

LIBFT_SRC = $(addprefix $(LIBFT_DIR), \
ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strlncpy.c	ft_strrchr.c\
ft_atoi.c       ft_isascii.c    ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c     ft_strtrim.c\
ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c    ft_substr.c\
ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c    ft_tolower.c\
ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c    ft_toupper.c\
ft_printf.c						ft_printf_make_str_cs.c			ft_printf_make_str_pdux.c\
ft_printf_make_str_spec1.c		ft_printf_make_str_spec2.c		ft_printf_print_format_string.c\
ft_printf_read_spec.c\
ft_dprintf.c	ft_vdprintf.c	ft_snprintf.c	ft_vsnprintf.c\
get_next_line.c					get_next_line_utils.c)
LIBFT_OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

bonus: $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS) $(LIBFT)
	$(CC) $(OBJ_CLIENT_BONUS) $(LIBFT_FLAGS) -o client
	$(CC) $(OBJ_SERVER_BONUS) $(LIBFT_FLAGS) -o server
	touch $@

client server: $(OBJ_CLIENT) $(OBJ_SERVER) $(LIBFT)
	$(CC) $(OBJ_CLIENT) $(LIBFT_FLAGS) -o client
	$(CC) $(OBJ_SERVER) $(LIBFT_FLAGS) -o server

$(LIBFT): $(LIBFT_SRC) $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER) $(HEADER_BONUS) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	rm -f bonus
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
