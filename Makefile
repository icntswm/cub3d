NAME = cub3d

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = -L libft/ -lft

HEADERS = cub3d.h

MLX = -framework OpenGL -framework AppKit -lmlx -I includes/

MAIN_SRC = cast_walls.c\
		cast_walls2.c\
		get_next_line\
		keys.c\
		key_funcs.c\
		main.c\
		mouse.c\
		parser\
		textures.c

PARSER = bool_handling.c\
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

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make fclean -C libft
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re