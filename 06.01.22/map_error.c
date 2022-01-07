#include "../includes/cub3d.h"

void	check_path_around_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != data->player_char)
			j++;
		if (data->map[i][j] == data->player_char)
			break ;
		i++;
	}
	// printf("position player_char: %d|%d\n", i, j);
	if (!((data->map[i - 1] && data->map[i - 1][j] == '0')
		|| (data->map[i + 1] && data->map[i + 1][j] == '0')
		|| data->map[i][j - 1] == '0' || data->map[i][j + 1] == '0'))
		ft_error(data, "path_player");
}

void	check_first_last_string(int j, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1' && check_s_t(data->map[j][i], 1))
			ft_error(data, "open_map");
		i++;
	}
}

void	check_error(t_data *data, int j, int i)
{
	while (data->map[j][i])
	{
		if (data->map[j][i] && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && check_s_t(data->map[j][i], 1)
			&& !check_plr(data->map[j][i]))
			ft_error(data, "incorr");
		if (data->map[j][i] == '0')
		{
			if ((data->map[j - 1] && ft_strlen(data->map[j - 1]) < i)
				|| (data->map[j - 1][i] && check_s_t(data->map[j - 1][i], 0)))
				ft_error(data, "open_map");
			if ((data->map[j + 1] && ft_strlen(data->map[j + 1]) < i)
				|| (data->map[j + 1][i] && check_s_t(data->map[j + 1][i], 0)))
				ft_error(data, "open_map");
		}
		if (data->map[j][i] && check_plr(data->map[j][i]) && !data->player_char)
			data->player_char = data->map[j][i];
		else if (data->map[j][i] && check_plr(data->map[j][i]) && data->player_char)
			ft_error(data, "player_mul");
		i++;
		if ((check_s_t(data->map[j][i], 0) || data->map[j][i] == '\n'
			|| data->map[j][i] == '\0') && (data->map[j][i - 1] != '1'
			&& check_s_t(data->map[j][i - 1], 1)))
			ft_error(data, "open_map");
	}
}

void	map_error(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	check_first_last_string(0, data);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && check_s_t(data->map[j][i], 0))
			i++;
		if (i == 0 && data->map[j][i] == '\0')
			ft_error(data, "wo_no");
		if (data->map[j][i] && data->map[j][i] != '1')
			ft_error(data, "open_map");
		check_error(data, j, i);
		j++;
		if (!data->map[j + 1])
		{
			check_first_last_string(j, data);
			break ;
		}
	}
	if (!data->player_char)
		ft_error(data, "player_char");
	check_path_around_player(data);
}
