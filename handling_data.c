#include "cub3d.h"

int	check_previous_compass(t_data *data, char *comp)
{
	if (comp[0] == 'N' && comp[1] == 'O' && !data->so
		&& !data->we && !data->ea)
		return (0);
	else if (comp[0] == 'S' && comp[1] == 'O' && data->no
		&& !data->we && !data->ea)
		return (0);
	else if (comp[0] == 'W' && comp[1] == 'E' && data->no
		&& data->so && !data->ea)
		return (0);
	else if (comp[0] == 'E' && comp[1] == 'A' && data->no
		&& data->so && data->we)
		return (0);
	else if (comp[0] == 'F' && data->no && data->so && data->we
		&& data->ea && !data->ceiling)
		return (0);
	else if (comp[0] == 'C' && data->no && data->so && data->we
		&& data->ea && data->floor)
		return (0);
	ft_error(data, "wr_order");
	return (1);
}

int	data_clipping(int i, t_data *data, char **str, char *comp)
{
	int	start;

	start = 0;
	if (*str)
		ft_error(data, "rep_param");
	check_previous_compass(data, comp);
	while (data->repfile[i] && (data->repfile[i] == ' '
			|| data->repfile[i] == '\t'))
		i++;
	start = i;
	while (data->repfile[i] && data->repfile[i] != ' '
		&& data->repfile[i] != '\t' && data->repfile[i] != '\n')
		i++;
	if (start == i)
		ft_error(data, "wo_no");
	*str = ft_substr(data->repfile, start, i - start);
	if (data->repfile[i] != '\n')
	{
		while (data->repfile[i] && data->repfile[i] != '\n'
			&& (data->repfile[i] == ' ' || data->repfile[i] == '\t'))
			i++;
		if (data->repfile[i] != '\n')
			ft_error(data, "incorr");
	}
	return (i);
}

int	data_validation(t_data *data)
{
	int	i;

	i = 0;
	// if (!(access(data->no, F_OK) == 0 && access(data->so, F_OK) == 0
	//     && access(data->we, F_OK) == 0 && access(data->ea, F_OK) == 0))
	//     ft_error(data, "text_error"); //проверка существования текстур
	while (data->floor[i])
	{
		if (!((data->floor[i] >= '0' && data->floor[i] <= '9')
				|| data->floor[i] == ',' || data->floor[i] == '-'))
			ft_error(data, "color_num");
		i++;
	}
	i = 0;
	while (data->ceiling[i])
	{
		if (!((data->ceiling[i] >= '0' && data->ceiling[i] <= '9')
				|| data->ceiling[i] == ',' || data->ceiling[i] == '-'))
			ft_error(data, "color_num");
		i++;
	}
	return (0);
}

int	param_selection(int i, t_data *data)
{
	if (i == 0 && i_is_zero_cmp(i, "NO", data))
		i = data_clipping(i + 2, data, &data->no, "NO");
	else if (i > 0 && i_isnt_zero_cmp(i, "NO", data))
		i = data_clipping(i + 2, data, &data->no, "NO");
	else if (i == 0 && i_is_zero_cmp(i, "SO", data))
		i = data_clipping(i + 2, data, &data->so, "SO");
	else if (i > 0 && i_isnt_zero_cmp(i, "SO", data))
		i = data_clipping(i + 2, data, &data->so, "SO");
	else if (i == 0 && i_is_zero_cmp(i, "WE", data))
		i = data_clipping(i + 2, data, &data->we, "WE");
	else if (i > 0 && i_isnt_zero_cmp(i, "WE", data))
		i = data_clipping(i + 2, data, &data->we, "WE");
	else if (i == 0 && i_is_zero_cmp(i, "EA", data))
		i = data_clipping(i + 2, data, &data->ea, "EA");
	else if (i > 0 && i_isnt_zero_cmp(i, "EA", data))
		i = data_clipping(i + 2, data, &data->ea, "EA");
	else if (i == 0 && i_is_zero_color(i, 'F', data))
		i = data_clipping(i + 1, data, &data->floor, "F");
	else if (i > 0 && i_isnt_zero_color(i, 'F', data))
		i = data_clipping(i + 1, data, &data->floor, "F");
	else if (i == 0 && i_is_zero_color(i, 'C', data))
		i = data_clipping(i + 1, data, &data->ceiling, "C");
	else if (i > 0 && i_isnt_zero_color(i, 'C', data))
		i = data_clipping(i + 1, data, &data->ceiling, "C");
	return (i);
}

void	handling_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->repfile[i])
	{
		i = param_selection(i, data);
		if (data->repfile[i] != ' ' && data->repfile[i] != '\t'
			&& data->repfile[i] != '\n')
			ft_error(data, "incorr");
		if (data->no && data->so && data->so && data->ea && data->floor
			&& data->ceiling)
			break ;
		i++;
	}
	printf("NO: |%s|\n", data->no);
	printf("SO: |%s|\n", data->so);
	printf("WE: |%s|\n", data->we);
	printf("EA: |%s|\n", data->ea);
	printf("F: |%s|\n", data->floor);
	printf("C: |%s|\n", data->ceiling);
	data_validation(data);
	read_map(i, data);
}
