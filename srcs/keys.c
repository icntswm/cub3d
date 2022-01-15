#include "cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player.x + data->player.dir_x * (SPEED + 0.1))][(int)(data->player.y)] != '1')
		data->player.x += data->player.dir_x * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y + data->player.dir_y * (SPEED + 0.1))] != '1')
		data->player.y += data->player.dir_y * SPEED;
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player.x - data->player.dir_x * (SPEED + 0.1))][(int)(data->player.y)] != '1')
		data->player.x -= data->player.dir_x * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y - data->player.dir_y * (SPEED + 0.1))] != '1')
		data->player.y -= data->player.dir_y * SPEED;
}

void	turn_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(ROT_SPEED) - data->player.dir_y * sin(ROT_SPEED);
	data->player.dir_y = old_dir_x * sin(ROT_SPEED) + data->player.dir_y * cos(ROT_SPEED);
	data->player.plane_x = data->player.plane_x * cos(ROT_SPEED) - data->player.plane_y * sin(ROT_SPEED);
	data->player.plane_y = old_plane_x * sin(ROT_SPEED) + data->player.plane_y * cos(ROT_SPEED);
}

void	turn_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-ROT_SPEED) - data->player.dir_y * sin(-ROT_SPEED);
	data->player.dir_y = old_dir_x * sin(-ROT_SPEED) + data->player.dir_y * cos(-ROT_SPEED);
	data->player.plane_x = data->player.plane_x * cos(-ROT_SPEED) - data->player.plane_y * sin(-ROT_SPEED);
	data->player.plane_y = old_plane_x * sin(-ROT_SPEED) + data->player.plane_y * cos(-ROT_SPEED);
}

int	keyhook(int keycode, t_data *data)
{
	// printf("%d\n", keycode);
	if (keycode == ESC)
		exit(0);
	if (keycode == W || keycode == UP)
		move_forward(data);
	if (keycode == S || keycode == DOWN)
		move_backward(data);
	if (keycode == A || keycode == LEFT)
		turn_left(data);
	if (keycode == D || keycode == RIGHT)
		turn_right(data);
	return (0);
}