#include "../includes/cub3d.h"

void	map_parser(char *file, t_data *data)
{
	int		fd_file;

	init_data(data);
	fd_file = open(file, O_RDONLY, 0644);
	if (fd_file == -1)
		ft_error(data, "open_file");
	else
	{
		reaplace_file(data, fd_file);
		close(fd_file);
	}
	handling_data(data);
}
