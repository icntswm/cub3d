#include "cub3d.h"

bool check_fl_cel_error(char a)
{
	return (a != ' ' && a != '\t' && !(a >= '0' && a <= '9') && a != ',' && a != '\n');
}

int	to_hex(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void	hext_char_to_int(t_data *data, char **array_atoi)
{
	long long r;
	long long g;
	long long b;

	if (!array_atoi[0] || !array_atoi[1] || !array_atoi[2])
		ft_error(data, "incorr");
	r = ft_atoi(array_atoi[0]);
	g = ft_atoi(array_atoi[1]);
	b = ft_atoi(array_atoi[2]);
	if (r > 255 || g > 255 || b > 255)
		ft_error(data, "rgb");
	if (data->floor == -1)
		data->floor = to_hex(r, g, b);
	else if (data->ceiling == -1)
		data->ceiling = to_hex(r, g, b);
}

int color_handling(int i, t_data *data)
{
	int start;
	char **array_atoi;
	int j;

	j = 0;
	start = 0;
	array_atoi = (char **)malloc(sizeof(char *) * 4);
	while (j < 4)
		array_atoi[j++] = NULL;
	j = 0;
	if (!array_atoi)
		exit(1);
	while(data->repfile[i] && data->repfile[i] != '\n')
	{
		while (data->repfile[i] && (data->repfile[i] == ' ' || data->repfile[i] == '\t') && data->repfile[i] != '\n')
			i++;
		start = i;
		while (data->repfile[i] && data->repfile[i] != ',' && data->repfile[i] != '\n')
		{
			if (check_fl_cel_error(data->repfile[i]))
				ft_error(data, "incorr");
			i++;
		}
		if (check_fl_cel_error(data->repfile[i]))
				ft_error(data, "incorr");
		if (i != start)
		{
			if (j == 3)
				ft_error(data, "num_rgb");
			array_atoi[j] = ft_substr(data->repfile, start, i - start);
			j++;
			if (j == 3)
				array_atoi[j] = NULL;
		}
		if (data->repfile[i] == '\n')
		{
			hext_char_to_int(data, array_atoi);
			break ;
		}
		i++;
	}
	if (array_atoi)
		free_array(array_atoi);
	if (j != 3)
		ft_error(data, "num_rgb");
	return(i);
}