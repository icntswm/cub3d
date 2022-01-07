#include "../includes/cub3d.h"

int	keyhook(int keycode)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 65307)//linux(ESC)
		exit(0);
	return (0);
}

void	ft_print_data(t_data *data)
{
	for(int i = 0; data->map[i]; i++)
		printf("[%d]: %s\n", i, data->map[i]);
	printf("NO: %s\n", data->no);
	printf("SO: %s\n", data->so);
	printf("WE: %s\n", data->we);
	printf("EA: %s\n", data->ea);
	printf("F: %d\n", data->floor);
	printf("C: %d\n", data->ceiling);
	printf("player: %c\n", data->player_char);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_background_image(t_data *data)
{
	int	i;
	int	j;

	data->tex.background.img = mlx_new_image(data->mlx.mlx, HEIGHT, WIDTH);
	data->tex.background.addr = mlx_get_data_addr(data->tex.background.img, \
		&data->tex.background.bits_per_pixel, \
		&data->tex.background.line_length, &data->tex.background.endian);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (i < WIDTH / 2)
				my_mlx_pixel_put(&data->tex.background, j, i, data->ceiling);
			else
				my_mlx_pixel_put(&data->tex.background, j, i, data->floor);
			j++;
		}
		i++;
	}
}

int	render_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->tex.background.img, 0, 0);
	return (0);
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window (data->mlx.mlx, data->mlx.win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1 || argc > 2)
	{
		write(2, "Error: too many/few arguments\n", 30);
		return (1);
	}
	map_parser(argv[1], &data);
	data.mlx.mlx = mlx_init();
	make_background_image(&data);
	data.mlx.win = mlx_new_window(data.mlx.mlx, HEIGHT, WIDTH, "Cub3d");
	mlx_key_hook(data.mlx.win, keyhook, NULL);
	// mlx_hook(data.mlx.win, 17, 0, exit, NULL);//change!!
	mlx_loop_hook(data.mlx.mlx, render_image, &data);
	mlx_loop(data.mlx.mlx);
	// ft_print_data(&data);
	// cleaning(&data);
	return (0);
}

// gcc *.c ../libft/*.c ../get_next_line/*.c -Wall -Wextra -Werror
// gcc *.c ../libft/*.c ../get_next_line/*.c -Wall -Wextra -Werror -I ../minilibx/ -L ../minilibx/ -lmlx -lm -lbsd -lX11 -lXext