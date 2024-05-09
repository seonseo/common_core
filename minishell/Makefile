NAME = pipex
HEADER = pipex.h
HEADER_BONUS = pipex_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(addprefix $(LIBFT_DIR), libft.h ft_printf.h get_next_line.h error_functions.h)
LIBFT_FLAGS = -Llibft -lft

SRC = pipex.c	ft_getenv.c	ft_execvpe.c
OBJ = $(patsubst %.c, %.o, $(SRC))

SRC_BONUS = pipex_bonus.c	pipex_bonus_execute_pipeline.c	pipex_bonus_execute_pipeline_here_doc.c\
pipex_bonus_child.c			pipex_bonus_here_doc.c			ft_getenv.c		ft_execvpe.c
OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

LIBFT_SRC = $(addprefix $(LIBFT_DIR), \
ft_isalpha.c    ft_memchr.c     ft_putchar_fd.c ft_strchr.c     ft_strlcpy.c    ft_strrchr.c	ft_atoi.c\
ft_atol.c		ft_isascii.c    ft_isspace.c	ft_memcmp.c     ft_putendl_fd.c ft_strdup.c     ft_strlen.c\
ft_strtrim.c	ft_bzero.c      ft_isdigit.c    ft_memcpy.c     ft_putnbr_fd.c  ft_striteri.c   ft_strmapi.c\
ft_substr.c		ft_calloc.c     ft_isprint.c    ft_memmove.c    ft_putstr_fd.c  ft_strjoin.c    ft_strncmp.c\
ft_tolower.c	ft_isalnum.c    ft_itoa.c       ft_memset.c     ft_split.c      ft_strlcat.c    ft_strnstr.c\
ft_toupper.c	ft_strlncpy.c	ft_strlncat.c	ft_strtol.c\
ft_printf.c						ft_printf_make_str_cs.c			ft_printf_make_str_pdux.c\
ft_printf_make_str_spec1.c		ft_printf_make_str_spec2.c		ft_printf_print_format_string.c\
ft_printf_read_spec.c\
ft_dprintf.c	ft_vdprintf.c	ft_snprintf.c	ft_vsnprintf.c\
get_next_line.c					get_next_line_utils.c\
error_functions.c				error_functions1.c				get_num.c)
LIBFT_OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT_FLAGS) -o $(NAME)
	touch $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $@

$(LIBFT): $(LIBFT_SRC) $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER) $(HEADER_BONUS) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f bonus
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
