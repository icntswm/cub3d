#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	(void)argv;
	if (argc == 1 || argc > 2)
	{
		write(2, "Error: too many/few arguments\n", 30);
		return (1);
	}
	map_parser(argv[1], &data);
	return (0);
}
