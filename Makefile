NAME = cub3D
NAME_L = cub3D_linux

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I includes/ -I libft/ -MMD

LIBFT = -L libft/ -lft

HEADERS = includes/cub3d.h

# MLX = -framework OpenGL -framework AppKit -lmlx -I includes/
MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit
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
DEP = $(OBJ:o=d)

PATH_LIB = libft/
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
	@echo "\n"
	@make -C mlx 2>/dev/null
	@make -C $(PATH_LIB)
	@echo "\033[0;32mCompiling cub3d...✅"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -I mlx $(OBJ) $(LIB) -I. -o $(NAME)
	@echo "\n\033[0;33m🥂Done and ready!🥂"

%.o: %.c $(HEADERS)
	@printf "\033[0;33mGenerating cub3d objects 🔜 %-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C $(PATH_LIB)
	@echo "\033[0;31mCleaning mlx..."
	@make clean -C mlx
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ) $(DEP)
	@echo "\n\033[0;32mCleaning process is competed!"

fclean: clean
	@rm -f $(NAME) $(NAME_L)
	@make fclean -C $(PATH_LIB)
	@make fclean -C mlx

test: all clean

re: fclean all

.PHONY: all clean fclean re test linux

include $(wildcard $(DEP))