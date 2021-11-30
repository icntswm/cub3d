#include "cub3d.h"

void	to_hex(t_data *data)
{
	int	check_error;

	check_error = make_hex(&data->floor);
	if (check_error == 1)
		ft_error(data, "rgb");
	else if (check_error == 2)
		ft_error(data, "num_rgb");
	check_error = make_hex(&data->ceiling);
	if (check_error == 1)
		ft_error(data, "rgb");
	else if (check_error == 2)
		ft_error(data, "num_rgb");
}

void	map_parser(char *file)
{
	t_data	data;
	int		fd_file;

	init_data(&data);
	fd_file = open(file, O_RDONLY, 0644);
	if (fd_file == -1)
		ft_error(&data, "file_open");
	else
	{
		reaplace_file(&data, fd_file);
		close(fd_file);
	}
	handling_data(&data);
	to_hex(&data);
	printf("color_floor: %s\n", data.floor);
	printf("color_celling: %s\n", data.ceiling);
	cleaning(&data);
}
