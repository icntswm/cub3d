/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <squickfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:57:24 by squickfi          #+#    #+#             */
/*   Updated: 2022/01/19 13:18:31 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyhook(int keycode, t_data *data)
{
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

void	press_keys(t_data *data)
{
	if (data->player_char == 'S' || data->player_char == 'W')
	{
		if (data->keys.left)
			turn_right(data);
		if (data->keys.right)
			turn_left(data);
	}
	else
	{
		if (data->keys.left)
			turn_left(data);
		if (data->keys.right)
			turn_right(data);
	}
	if (data->keys.forward)
		move_forward(data);
	if (data->keys.backward)
		move_backward(data);
}