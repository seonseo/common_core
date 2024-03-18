NAME = fdf
HEADER = fdf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_DIR = mlx/
MLX = libmlx.dylib
MLX_HEADER = $(MLX_DIR)mlx.h

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(addprefix $(LIBFT_DIR), libft.h ft_printf.h get_next_line.h)
LIBFT_FLAGS = -Llibft -lft

SRC = fdf.c		fdf1.c				fdf_parse_input_to_int_matrix.c	fdf_parse_input_to_int_matrix1.c\
fdf_convert_map_to_point_matrix.c	fdf_create_wireframe.c					fdf_create_wireframe1.c\
fdf_key_hook.c						fdf_exit_error.c		fdf_isometric_projection.c
OBJ = $(patsubst %.c, %.o, $(SRC))

LIBFT_SRC = $(addprefix $(LIBFT_DIR), \
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
LIBFT_OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_DIR)$(MLX)
	$(CC) $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)
	cp $(MLX_DIR)$(MLX) .

$(LIBFT): $(LIBFT_SRC) $(LIBFT_HEADER)
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER) $(MLX_HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re
