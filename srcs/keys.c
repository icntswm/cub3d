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
		ft_exit(data);
	if (keycode == W || keycode == UP)
		data->keys.forward = 1;
	if (keycode == S || keycode == DOWN)
		data->keys.backward = 1;
	if (keycode == A || keycode == LEFT)
		data->keys.left = 1;
	if (keycode == D || keycode == RIGHT)
		data->keys.right = 1;
	return (0);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode == W || keycode == UP)
		data->keys.forward = 0;
	if (keycode == S || keycode == DOWN)
		data->keys.backward = 0;
	if (keycode == A || keycode == LEFT)
		data->keys.left = 0;
	if (keycode == D || keycode == RIGHT)
		data->keys.right = 0;
	return (0);
}

/*
void	turn_left(t_data *data)
{
	if (data->map[(int)(data->player.x + -sqrt(1 - pow(data->player.dir_x, 2)) * (SPEED + 0.1))][(int)(data->player.y)] != '1')
		data->player.x += -sqrt(1 - pow(data->player.dir_x, 2)) * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y + -sqrt(1 - pow(data->player.dir_y, 2)) * (SPEED + 0.1))] != '1')
		data->player.y += -sqrt(1 - pow(data->player.dir_y, 2)) * SPEED;
}

void	turn_right(t_data *data)
{
	if (data->map[(int)(data->player.x + sqrt(1 - pow(data->player.dir_x, 2)) * (SPEED + 0.1))][(int)(data->player.y)] != '1')
		data->player.x += sqrt(1 - pow(data->player.dir_x, 2)) * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y + sqrt(1 - pow(data->player.dir_y, 2)) * (SPEED + 0.1))] != '1')
		data->player.y += sqrt(1 - pow(data->player.dir_y, 2)) * SPEED;
}
*/