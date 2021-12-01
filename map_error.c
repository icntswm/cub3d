#include "cub3d.h"

void    map_error(int size, t_data *data)
{
    int i;
    int j;

    j = 1;
    i = 0;
    (void)size;
    while (data->map[0][i])
    {
        // int start = i;
        // while (data->map[0][i] && (data->map[0][i] == ' ' || data->map[0][i] == '\t'))
        // {
        //     if (start - 1 >= 0 && i - 1 >= 0 && data->map[1] && ft_strlen(data->map[1]) > i && data->map[0][i - 1] != ' ' && data->map[0][i - 1] != '\t'
        //         && data->map[1][start - 1] != '1')
        //         ft_error(data, "open_map");
        //     if (data->map[1] && ft_strlen(data->map[1]) > i && (data->map[0][i] == ' ' || data->map[0][i] == '\t')
        //         && (data->map[1][i] != '1' && data->map[1][i] != ' ' && data->map[1][i] != '\t'))
        //         ft_error(data, "open_map");
        //     i++;
        //     if (data->map[1] && ft_strlen(data->map[1]) > i && data->map[0][i] != ' ' && data->map[0][i] != '\t'
        //         && data->map[1][i] != '1')
        //             ft_error(data, "open_map");
        // }    
        if (data->map[0][i] != '1' && data->map[0][i] != ' ' && data->map[0][i] != '\t')
            ft_error(data, "open_map");
        i++;
    }
    printf("SIZE: %d\n", size);
    while (data->map[j])
    {
        i = 0;
        if (data->map[j][0] != '1' && data->map[j][0] != ' ' && data->map[j][0] != '\t')
            ft_error(data, "open_map");
        while (i < ft_strlen(data->map[j]))
        {
            int start = i;
            while (i < ft_strlen(data->map[j]) && (data->map[j][i] == ' ' || data->map[j][i] == '\t'))//////////
            {
                if (start - 1 >= 0 && data->map[j][start - 1] != '1')
                {
                    printf("uuuuu\n");
                    ft_error(data, "open_map");
                }
                if (start - 1 >= 0 && i - 1 >= 0 && data->map[j + 1] && ft_strlen(data->map[j + 1]) > i && data->map[j][i - 1] != ' '
                    && data->map[j][i - 1] != '\t'
                    && (data->map[j + 1][start - 1] != '1' && data->map[j + 1][start - 1] != ' ' && data->map[j + 1][start - 1] != '\t'))
                {
                        printf("KEK1\n");
                        ft_error(data, "open_map");
                    }
                if (start - 1 >= 0 && i - 1 >= 0 && data->map[j - 1] && ft_strlen(data->map[j - 1]) > i && data->map[j][i - 1] != ' '
                    && data->map[j][i - 1] != '\t'
                    && (data->map[j - 1][start - 1] != '1' && data->map[j - 1][start - 1] != ' ' && data->map[j - 1][start - 1] != '\t'))
                {
                        printf("KEK666\n");
                        ft_error(data, "open_map");
                    }


                if (data->map[j + 1] && ft_strlen(data->map[j + 1]) > i && (data->map[j][i] == ' ' || data->map[j][i] == '\t')
                    && (data->map[j + 1][i] != '1' && data->map[j + 1][i] != ' ' && data->map[j + 1][i] != '\t'))
                    {
                        printf("KEK2))))|%d|%c|\n", j, data->map[j][i]);
                        ft_error(data, "open_map");
                    }
                if (data->map[j - 1] && ft_strlen(data->map[j - 1]) > i && (data->map[j][i] == ' ' || data->map[j][i] == '\t')
                    && (data->map[j - 1][i] != '1' && data->map[j - 1][i] != ' ' && data->map[j - 1][i] != '\t'))
                    {
                printf("|%d|i-start: %d | strlen: %d\n", j, i-start, ft_strlen(data->map[j]));
                        printf("KEK2((((\n");
                        ft_error(data, "open_map");
                    }
                i++;
                if ((data->map[j][i] != ' ' && data->map[j][i] != '\t' && data->map[j][i] != '1' && i != ft_strlen(data->map[j]))
                    || i - start == ft_strlen(data->map[j]))
                {
                        printf("-----KEK2\n");
                        ft_error(data, "open_map");
                    }
                if (data->map[j + 1] && ft_strlen(data->map[j + 1]) > i && data->map[j][i] != ' ' && data->map[j][i] != '\t'
                    && (data->map[j + 1][i] != '1' && data->map[j + 1][i] != ' ' && data->map[j + 1][i] != '\t'))
                    {
                        printf("KEK3|%d|\n", j);
                        ft_error(data, "open_map");
                    }
                if (data->map[j - 1] && ft_strlen(data->map[j - 1]) > i && data->map[j][i] != ' ' && data->map[j][i] != '\t'
                    && (data->map[j - 1][i] != '1' && data->map[j - 1][i] != ' ' && data->map[j - 1][i] != '\t'))
                    {
                        printf("KEK3555|%d|\n", j);
                        ft_error(data, "open_map");
                    }
                // if (data->map[0] && ft_strlen(data->map[0]) < i && data->map[1][i] != ' ' && data->map[1][i] != '\t'
                //     && data->map[2][i] != '1')
                //     ft_error(data, "open_map");
            }
            
            if (!data->player && (data->map[j][i] == 'N' || data->map[j][i] == 'S'
                ||data->map[j][i] == 'W' || data->map[j][i] == 'E'))
                data->player = data->map[j][i];
            else if (data->player && (data->map[j][i] == 'N' || data->map[j][i] == 'S'
                ||data->map[j][i] == 'W' || data->map[j][i] == 'E'))
                {
                        printf("KE......K1\n");
                        ft_error(data, "player_mul");
                    }
            else if (i != ft_strlen(data->map[j]) && data->map[j][i] != '1' && data->map[j][i] != '0' && data->map[j][i] != 'N'
                && data->map[j][i] != 'S' && data->map[j][i] != 'W' && data->map[j][i] != 'E'
                && data->map[j][i] != ' ' && data->map[j][i] != '\t')
                {
                    printf("------------KE......K1|%d|%c|\n", j, data->map[j][i]);
                ft_error(data, "incorr");
                }
            if ((data->map[j][i] == '0' || data->map[j][i] == 'N'
                || data->map[j][i] == 'S' || data->map[j][i] == 'W' || data->map[j][i] == 'E')
                && ((data->map[j + 1] && (data->map[j + 1][i] == ' ' || data->map[j + 1][i] == '\t'
                || ft_strlen(data->map[j + 1]) - 1 <= i || (i - 1 >= 0 && data->map[j + 1][i - 1] == ' '))) || (data->map[j - 1] && (data->map[j - 1][i] == ' ' || data->map[j - 1][i] == '\t'
                || ft_strlen(data->map[j - 1]) - 1 <= i || (i - 1 >= 0 && data->map[j - 1][i - 1] == ' ')))))
                {
                        printf("KEK1|%d|%d|%c|\n",j, i, data->map[j][i]);
                        ft_error(data, "open_map");
                    };
            i++;
            if (i == ft_strlen(data->map[j]) - 1 && data->map[j][i] != '1' && data->map[j][i] != ' ' && data->map[j][i] != '\t')
                {
                        printf("KEK-=1\n");
                        ft_error(data, "open_map");
                    }
            if (data->map[j + 1] && ft_strlen(data->map[j + 1]) > i && i == ft_strlen(data->map[j]) - 1
                && data->map[j + 1][i] != '1' && data->map[j + 1][i] != ' ' && data->map[j + 1][i] != '\t')
            {
                printf("LOL5674|%d|\n", j);
                ft_error(data, "open_map");
            }
        }
        j++;
        if (j == size)
        {
            i = 0;
            while (data->map[j][i])
            {
                if (data->map[j][i] != '1' && data->map[j][i] != ' ' && data->map[j][i] != '\t')
                    ft_error(data, "open_map");
                i++;
            }
            break ;
        }
        //     break ;
        // while (i < ft_strlen(data->map[j]))
        // {
        //     int start = i - 1;;
        //     while (data->map[j][i] && (data->map[j][i] == ' ' || data->map[j][i] == '\t'))
        //     {
        //         if (data->map[j][start] != '1')
        //             ft_error(data, "open_map");
        //         i++;
        //         if (data->map[j][i] && data->map[j][i] != ' ' && data->map[j][i] != '\t' && data->map[j][i] != '1')
        //             ft_error(data, "open_map");
        //     }
            // if (j == 3)
            //     printf("%c|%c\n", data->map[j + 1][ft_strlen(data->map[j + 1]) - 1], data->map[j][i - 1]);
            
            // else if (!data->player && (data->map[j][i] == 'N' || data->map[j][i] == 'S'
            //     ||data->map[j][i] == 'W' || data->map[j][i] == 'E'))
            //     data->player = data->map[j][i];
            // else if (data->player && (data->map[j][i] == 'N' || data->map[j][i] == 'S'
            //     ||data->map[j][i] == 'W' || data->map[j][i] == 'E'))
            //     ft_error(data, "player");
            // else if (data->map[j][i] != '1' && data->map[j][i] != '0' && data->map[j][i] != 'N'
            //     && data->map[j][i] != 'S' && data->map[j][i] != 'W' && data->map[j][i] != 'E'
            //     && data->map[j][i] != ' ' && data->map[j][i] != '\t')
            //     ft_error(data, "incorr");
            // if (i == ft_strlen(data->map[j]) - 1 && data->map[j][i] != '1')
            //     ft_error(data, "open_map");
                // printf("|%d||%c\n", j, data->map[j][i]);
        //     i++;    
        // }
        // printf("j: %d\n", j);
        // j++;
        // if (j == size)
        // {
        //     i = 0;
        //     // printf("j: %d\n", j);
        //     while (data->map[j][i])
        //     {
        //         while (data->map[j][i] && (data->map[j][i] == ' ' || data->map[j][i] == '\t'))
        //             i++;
        //         if (data->map[j][i] != '1' && data->map[j][i] != ' ' && data->map[j][i] != '\t')
        //             ft_error(data, "open_map");
        //         i++;
        //     }
        //     break ;
    }
    if (!data->player)
        ft_error(data, "player");
    printf("player: %c\n", data->player);
}
