#include "cub3d.h"

int	keyhook(int keycode)
{
	if (keycode == 53)
		exit(0);
	// if (keycode == 65307)//linux(ESC)
	// 	exit(0);
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
	exit(0);
}

void	init_coords(t_data *data, int x, int y)
{
	if (data->player_char == 'N')
		x = -1;
	else if (data->player_char == 'S')
		x = 1;
	else if (data->player_char == 'E')
		y = 1;
	else
		y = -1;
	data->player.dir_x = x;
	data->player.dir_y = y;
	if (x)
	{
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
}

void	init_player_data(t_data *data)
{
	int	i;
	int	j;

	init_coords(data, 0, 0);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->player_char)
			{
				data->player.y = (double)i + 0.5;
				data->player.x = (double)j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	raycaster(t_data *data)
{
	int	i;

	i = 0;
	while (i < 512)
	{
		data->player.camera = 2 * (i / (double)512) - 1;
		data->player.ray_dir_x = data->player.dir_x + data->player.plane_x * data->player.camera;
		data->player.ray_dir_y = data->player.dir_y + data->player.plane_y * data->player.camera;
		data->player.delta_dest_x = fabs(1 / data->player.ray_dir_x);
		data->player.delta_dest_y = fabs(1 / data->player.ray_dir_y);
	}
	return (0);
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
	init_player_data(&data);
	data.mlx.mlx = mlx_init();
	make_background_image(&data);
	data.mlx.win = mlx_new_window(data.mlx.mlx, HEIGHT, WIDTH, "Cub3d");
	mlx_key_hook(data.mlx.win, keyhook, NULL);
	// mlx_hook(data.mlx.win, 17, 0, exit, NULL);//change!!
	mlx_loop_hook(data.mlx.mlx, render_image, &data);
	mlx_loop(data.mlx.mlx);
	// ft_print_data(&data);
	cleaning(&data);
	return (0);
}

// gcc *.c ../libft/*.c ../get_next_line/*.c -Wall -Wextra -Werror
// gcc *.c ../libft/*.c ../get_next_line/*.c -Wall -Wextra -Werror -I ../minilibx/ -L ../minilibx/ -lmlx -lm -lbsd -lX11 -lXext