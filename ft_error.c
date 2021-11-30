#include "cub3d.h"

void	ft_error(t_data *data, char *error)
{
	cleaning(data);
	if (ft_strncmp(error, "rgb", 3) == 0)
		write(2, "Error: rgb color must be from 0 to 255\n", 39);
	else if (ft_strncmp(error, "num_rgb", 7) == 0)
		write(2, "Error: rgb color must consist of 3 numbers\n", 43);
	else if (ft_strncmp(error, "open_file", 9) == 0)
		write(2, "Error: file not found or permission denied\n", 43);
	else if (ft_strncmp(error, "incorr", 8) == 0)
		write(2, "Error: parameters are incorrect\n", 32);
	else if (ft_strncmp(error, "wo_no", 5) == 0)
		write(2, "Error: empty string without arguments\n", 38);
	else if (ft_strncmp(error, "rep_param", 9) == 0)
		write(2, "Error: repeating parameters\n", 28);
	else if (ft_strncmp(error, "wr_order", 8) == 0)
		write(2, "Error: wrong order (NO, SO, WE, EA, F, C, *map*)\n", 49);
	else if (ft_strncmp(error, "text_error", 8) == 0)
		write(2, "Error: textures do not exist or access is denied\n", 49);
	else if (ft_strncmp(error, "color_num", 9) == 0)
		write(2, "Error: F/C should only contain numbers and a sep ','\n", 53);
	else if (ft_strncmp(error, "open_map", 8) == 0)
		write(2, "Error: open map\n", 16);
	exit (1);
}
