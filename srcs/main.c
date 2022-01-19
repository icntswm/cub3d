/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <squickfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:57:26 by squickfi          #+#    #+#             */
/*   Updated: 2022/01/19 13:23:22 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				data->mlx.prev_x_mouse = -1;
				data->mlx.is_mouse_active = -1;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	render_image(t_data *data)
{
	press_keys(data);
	cast_walls(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
		data->tex.picture.img, 0, 0);
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
	init_player_data(&data);
	data.mlx.mlx = mlx_init();
	get_textures(&data);
	make_image(&data, &data.tex.picture);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	mlx_mouse_hook(data.mlx.win, small_mousehook, &data);
	mlx_hook(data.mlx.win, 6, 0, mousehook, &data);
	mlx_hook(data.mlx.win, 2, 0, keyhook, &data);
	mlx_hook(data.mlx.win, 3, 0, keyrelease, &data);
	mlx_hook(data.mlx.win, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx.mlx, render_image, &data);
	mlx_loop(data.mlx.mlx);
	cleaning(&data);
	return (0);
}
