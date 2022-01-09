#include "cub3d.h"

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	// data->player_char = '\0';
	data->floor = -1;
	data->ceiling = -1;
}
