NAME = cub3D
NAME_L = cub3D_linux

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -I includes/ -I libft/

LIBFT = -L libft/ -lft

HEADERS = includes/cub3d.h

MLX = -framework OpenGL -framework AppKit -lmlx -I includes/
MLX_LINUX = -I includes/ -lmlx -lm -lbsd -lX11 -lXext

MAIN_SRC = cast_walls.c\
		cast_walls2.c\
		keys.c\
		key_funcs.c\
		key_funcs2.c\
		main.c\
		mouse.c\
		textures.c

PARSER = bool_handling.c\
		bool_handling2.c\
		cleaning.c\
		ft_error.c\
		handling_color.c\
		handling_data.c\
		init_data.c\
		map_error.c\
		map_parser.c\
		read_map.c\
		replace_file.c

GNL = get_next_line.c\
		get_next_line_utils.c

SRC = $(addprefix srcs/, $(MAIN_SRC))\
		$(addprefix srcs/parser/, $(PARSER))\
		$(addprefix srcs/get_next_line/, $(GNL))

OBJ = $(SRC:c=o)

all: $(NAME)

linux: $(NAME_L)

$(NAME_L): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX_LINUX) -o $(NAME_L)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(FLAGS) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make fclean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_L)

test: all clean

re: fclean all

.PHONY: all clean fclean re test linux
