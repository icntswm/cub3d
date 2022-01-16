#include "cub3d.h"

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

void	make_image(t_data *data, t_img *img)
{
	img->img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, \
		&img->bits_per_pixel, \
		&img->line_length, &img->endian);
}

void	get_textures(t_data *data)
{
	data->tex.no.img = mlx_xpm_file_to_image(data->mlx.mlx, data->no, &data->tex.no.width, &data->tex.no.height);
	data->tex.ea.img = mlx_xpm_file_to_image(data->mlx.mlx, data->ea, &data->tex.ea.width, &data->tex.ea.height);
	data->tex.we.img = mlx_xpm_file_to_image(data->mlx.mlx, data->we, &data->tex.we.width, &data->tex.we.height);
	data->tex.so.img = mlx_xpm_file_to_image(data->mlx.mlx, data->so, &data->tex.so.width, &data->tex.so.height);
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
				data->player.y = (double)j + 0.5;
				data->player.x = (double)i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
	data->mlx.prev_x_mouse = -1;
	data->mlx.is_mouse_active = -1;
}

int	raycaster(t_data *data)
{
	for (int i = 0; i < WIDTH; i++)
	{
		data->player.camera = 2 * i / (double)WIDTH - 1;
		data->player.ray_dir_x = data->player.dir_x + data->player.plane_x * data->player.camera;
    	data->player.ray_dir_y = data->player.dir_y + data->player.plane_y * data->player.camera;

		data->player.map_x = (int)data->player.x;
		data->player.map_y = (int)data->player.y;

		data->player.delta_dest_x = fabs(1 / data->player.ray_dir_x);
		data->player.delta_dest_y = fabs(1 / data->player.ray_dir_y);

		if(data->player.ray_dir_x < 0)
		{
			data->player.step_x = -1;
			data->player.side_dest_x = (data->player.x - (double)data->player.map_x) * data->player.delta_dest_x;
		}
		else
		{
			data->player.step_x = 1;
			data->player.side_dest_x = ((double)data->player.map_x + 1.0 - data->player.x) * data->player.delta_dest_x;
		}
		if(data->player.ray_dir_y < 0)
		{
			data->player.step_y = -1;
			data->player.side_dest_y = (data->player.y - (double)data->player.map_y) * data->player.delta_dest_y;
		}
		else
		{
			data->player.step_y = 1;
			data->player.side_dest_y = ((double)data->player.map_y + 1.0 - data->player.y) * data->player.delta_dest_y;
		}

		data->player.hit = 0;

		while (data->player.hit == 0)
		{
			if(data->player.side_dest_x < data->player.side_dest_y)
			{
				data->player.side_dest_x += data->player.delta_dest_x;
				data->player.map_x += data->player.step_x;
				data->player.side = 0;
			}
			else
			{
				data->player.side_dest_y += data->player.delta_dest_y;
				data->player.map_y += data->player.step_y;
				data->player.side = 1;
			}
			if (data->map[data->player.map_x][data->player.map_y] == '1')
				data->player.hit = 1;
		}

		if(data->player.side == 0)
			data->player.wall_dist = (data->player.side_dest_x - data->player.delta_dest_x);
		else
			data->player.wall_dist = (data->player.side_dest_y - data->player.delta_dest_y);

		data->player.wall_height = (int)(HEIGHT / data->player.wall_dist);

		data->player.draw_start = -data->player.wall_height / 2 + HEIGHT / 2 + data->mlx.view_height;
		if(data->player.draw_start < 0)
			data->player.draw_start = 0;
		data->player.draw_end = data->player.wall_height / 2 + HEIGHT / 2 + data->mlx.view_height;
		if(data->player.draw_end >= HEIGHT)
			data->player.draw_end = HEIGHT - 1;

		int color = 0x000000FF;
		if (data->player.side == 1)
			color /= 2;

		for (int j = 0; j < HEIGHT; j++)
		{
			if (j < data->player.draw_start || j > data->player.draw_end)
			{
				if (j < HEIGHT / 2 + data->mlx.view_height)
					my_mlx_pixel_put(&data->tex.background, i, j, data->ceiling);
				else
					my_mlx_pixel_put(&data->tex.background, i, j, data->floor);
			}
			else
				my_mlx_pixel_put(&data->tex.background, i, j, color);
		}
	}
	return (0);
}

int	render_image(t_data *data)
{
	raycaster(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->tex.background.img, 0, 0);
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->tex.no.img, 0, 0);
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
	ft_memset(&data, 0, sizeof(t_data));
	map_parser(argv[1], &data);
	printf("%s\n", data.no);
	init_player_data(&data);
	// get_textures(&data);
	data.mlx.mlx = mlx_init();
	make_image(&data, &data.tex.background);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	// mlx_mouse_hook(data.mlx.win, small_mousehook, &data);
	mlx_hook(data.mlx.win, 6, 0, mousehook, &data);
	mlx_hook(data.mlx.win, 2, 0, keyhook, &data);
	mlx_hook(data.mlx.win, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx.mlx, render_image, &data);
	mlx_loop(data.mlx.mlx);
	cleaning(&data);
	return (0);
}

// gcc *.c ../libft/*.c ../get_next_line/*.c ../main.c -Wall -Wextra -Werror
// gcc *.c ../libft/*.c ../get_next_line/*.c ../main.c -Wall -Wextra -Werror
// gcc *.c ../libft/*.c ../get_next_line/*.c -Wall -Wextra -Werror -I ../minilibx/ -L ../minilibx/ -lmlx -lm -lbsd -lX11 -lXext