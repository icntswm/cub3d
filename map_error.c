#include "cub3d.h"

void    map_error(int size, t_data *data)
{
    int i;
    int j;

    i = 0;
    (void)size;
    // printf("SIZE: %d\n", size);
    while (data->map[0][i])
    {
        if (data->map[0][i] != '1' && data->map[0][i] != ' ' && data->map[0][i] != '\t')
            ft_error(data, "open_map");
        i++;
    }
    j = 1;
    while (data->map[j])
    {
        // printf("map[%d]: %s\n", j, data->map[j]);
        i = 0;
        while (data->map[j][i] && (data->map[j][i] == ' ' || data->map[j][i] == '\t'))
            i++;
        if (i == 0 && data->map[j][i] == '\0')
            ft_error(data, "wo_no");
        if (data->map[j][i] && data->map[j][i] != '0' && data->map[j][i] != '1' && data->map[j][i] != 'N' &&
            data->map[j][i] != 'S' && data->map[j][i] != 'E' && data->map[j][i] != 'W')
           ft_error(data, "incorr");
        else if (data->map[j][i] && data->map[j][i] != '1')
            ft_error(data, "open_map");
        while (data->map[j][i])
        {
            if (data->map[j][i] && data->map[j][i] != '0' && data->map[j][i] != '1' && data->map[j][i] != 'N' &&
                data->map[j][i] != 'S' && data->map[j][i] != 'E' && data->map[j][i] != 'W' && data->map[j][i] != ' ' && data->map[j][i] != '\t')
                ft_error(data, "incorr");
            if (data->map[j][i] == '0')
            {
                if ((data->map[j - 1] && ft_strlen(data->map[j - 1]) < i) || (data->map[j - 1][i] && (data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\t')))
                    ft_error(data, "open_map");
                if ((data->map[j + 1] && ft_strlen(data->map[j + 1]) < i)
                    || (data->map[j + 1][i] && (data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\t')))
                    ft_error(data, "open_map");
            }
            if (data->map[j][i] && (data->map[j][i] == 'N' || data->map[j][i] == 'S' || data->map[j][i] == 'E' || data->map[j][i] == 'W'))
            {
                if (data->player)
                    ft_error(data, "player_mul");
                data->player = data->map[j][i];
            }
            i++;
        }
        j++;
        if (!data->map[j + 1])
        {
            // printf("map[%d]: %s\n", j, data->map[j]);
            i = 0;
            while (data->map[j][i])
            {
                if (data->map[j][i] != '1' && data->map[j][i] != ' ' && data->map[j][i] != '\t')
                    ft_error(data, "open_map");
                i++;
            }
            break ;
        }
    }
    if (!data->player)
        ft_error(data, "player");
    // printf("player: %c\n", data->player);
}
