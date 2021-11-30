#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_data
{
    char    *repfile;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *floor;
    char    *ceiling;
    char    **map;
}               t_data;


int     main(int argc, char **argv);
void	init_data(t_data *data);
void	reaplace_file(t_data *data, int fd_file);
void	map_parser(char *file);
int     make_hex(char **hex);
void	handling_data(t_data *data);
void	handling_floar_and_ceiling(int i, t_data *data);
void	ft_error(t_data *data, char *error);
void	cleaning(t_data *data);
void	free_array(char **array);

#endif