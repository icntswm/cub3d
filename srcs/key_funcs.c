/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squickfi <squickfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:01:36 by squickfi          #+#    #+#             */
/*   Updated: 2022/01/20 14:02:10 by squickfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player.x + data->player.dir_x * \
		(SPEED + 0.1))][(int)(data->player.y)] != '1')
		data->player.x += data->player.dir_x * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y + \
		data->player.dir_y * (SPEED + 0.1))] != '1')
		data->player.y += data->player.dir_y * SPEED;
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player.x - data->player.dir_x * \
		(SPEED + 0.1))][(int)(data->player.y)] != '1')
		data->player.x -= data->player.dir_x * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y - \
		data->player.dir_y * (SPEED + 0.1))] != '1')
		data->player.y -= data->player.dir_y * SPEED;
}

// void	move_left(t_data *data)
// {
	
// }

// void	move_right(t_data *data)
// {
	
// }
