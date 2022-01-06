#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1 || argc > 2)
	{
		write(2, "Error: too many/few arguments\n", 30);
		return (1);
	}
	map_parser(argv[1], &data);
	for(int i = 0; data.map[i]; i++)
		printf("[%d]: %s\n", i, data.map[i]);
	printf("NO: %s\n", data.no);
	printf("SO: %s\n", data.so);
	printf("WE: %s\n", data.we);
	printf("EA: %s\n", data.ea);
	printf("F: %d\n", data.floor);
	printf("C: %d\n", data.ceiling);
	printf("player: %c\n", data.player);
	// cleaning(&data);
	return (0);
}

// gcc *.c ../libft/*.c ../get_next_line/*.c -Wall -Wextra -Werror