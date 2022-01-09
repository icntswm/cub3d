NAME = cub3d

CC = gcc

FLAGS = -Wall -Wextra -Werror -I includes -I libft

LIBFT = -lft -L ./libft/

HEADERS = cub3d.h get_next_line.h

MLX = -framework OpenGL -framework AppKit -lmlx

GNL_SRC = get_next_line.c\
			get_next_line_utils.c

PARSER_SRC = bool_handling.c\
			cleaning.c\
			ft_error.c\
			handling_color.c\
			handling_data.c\
			init_data.c\
			map_error.c\
			map_parser.c\
			read_map.c\
			replace_file.c

MAIN_SRC = main.c

SRC = $(addprefix ./srcs/parser/, $(PARSER_SRC))\
	$(addprefix ./srcs/get_next_line/, $(GNL_SRC))\
	$(addprefix ./srcs/, $(MAIN_SRC))

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(LIBFT) $(MLX) -c $< -o $@

clean:
	make fclean -C libft/
	rm -f $(OBJ)

fclean:
	make fclean -C libft/
	rm -f $(OBJ)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

# gcc srcs/*.c srcs/get_next_line/*.c srcs/parser/*.c libft/*.c -I includes -lmlx -framework OpenGL -framework AppKit