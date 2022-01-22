/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <squickfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:56:50 by squickfi          #+#    #+#             */
/*   Updated: 2022/01/20 14:20:16 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_ray_directions_and_distances(t_data *data, int i)
{
	data->floor_cast.ray_dir_x_l = data->player.dir_x - data->player.plane_x;
	data->floor_cast.ray_dir_y_l = data->player.dir_y - data->player.plane_y;
	data->floor_cast.ray_dir_x_l = data->player.dir_x + data->player.plane_x;
	data->floor_cast.ray_dir_y_l = data->player.dir_y + data->player.plane_y;
	data->floor_cast.pos = i - HEIGHT / 2;
	data->floor_cast.pos_z = 0.5 * HEIGHT;
	data->floor_cast.row_distance = data->floor_cast.pos_z / (double)data->floor_cast.pos;
}

static void	find_steps_and_coords(t_data *data)
{
	data->floor_cast.step_x = data->floor_cast.row_distance * \
		(data->floor_cast.ray_dir_x_r - data->floor_cast.ray_dir_x_l) / WIDTH;
	data->floor_cast.step_y = data->floor_cast.row_distance * \
		(data->floor_cast.ray_dir_y_r - data->floor_cast.ray_dir_y_l) / WIDTH;
	data->floor_cast.x = data->player.x + data->floor_cast.row_distance * \
		data->floor_cast.ray_dir_x_l;
	data->floor_cast.y = data->player.y + data->floor_cast.row_distance * \
		data->floor_cast.ray_dir_y_l;
}

void	put_horizontal_line(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < WIDTH)
	{
		data->floor_cast.cell_x = (int)data->floor_cast.x;
		data->floor_cast.cell_y = (int)data->floor_cast.y;
		data->floor_cast.tex_x = (int)(data->tex.no.width * \
			(data->floor_cast.x - data->floor_cast.cell_x));// & (data->tex.no.width - 1);
		data->floor_cast.tex_y = (int)(data->tex.no.width * \
			(data->floor_cast.y - data->floor_cast.cell_y));// & (data->tex.no.width - 1);
		data->floor_cast.x += data->floor_cast.step_x;
		data->floor_cast.y += data->floor_cast.step_y;

		int color = get_pixel_color(&data->tex.no, data->floor_cast.tex_x, data->floor_cast.tex_y);
		my_mlx_pixel_put(&data->tex.picture, j, i, color);
		color = get_pixel_color(&data->tex.so, data->floor_cast.tex_x, data->floor_cast.tex_y);
		my_mlx_pixel_put(&data->tex.picture, j, HEIGHT - i - 1, color);
		// printf("......%d\n", i);

		j++;
	}
}

void	cast_floor(t_data *data)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		find_ray_directions_and_distances(data, i);
		find_steps_and_coords(data);
		// printf("!!!!!!!\n");
		put_horizontal_line(data, i);
	}
}