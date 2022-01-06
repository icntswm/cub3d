#include "cub3d.h"

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->player = '\0';
	// data->repfile = NULL;
	// data->no = NULL;
	// data->so = NULL;
	// data->we = NULL;
	// data->ea = NULL;
	data->floor = -1;
	data->ceiling = -1;
	// data->map = NULL;
}
