#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <limits.h>
#include <mlx.h>

# define HEIGHT 1280
# define WIDTH 720

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_tex
{
	struct s_img	background;
	struct s_img	no;
	struct s_img	ea;
	struct s_img	so;
	struct s_img	we;
}			t_tex;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct s_data
{
	char			player_char;//!!!!!!!!!
	char			*repfile;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor;
	int				ceiling;
	char			**map;
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_tex	tex;
}					t_data;


int		main(int argc, char **argv);
void	init_data(t_data *data);
void	reaplace_file(t_data *data, int fd_file);
void	map_parser(char *file, t_data *data);
void	make_hex(t_data *data);
void	handling_data(t_data *data);
int		color_handling(int i, t_data *data);
void	read_map(int i, t_data *data);
void	map_error(t_data *data);

//bool
bool	i_is_zero_color(int i, char a, t_data *data);
bool	i_isnt_zero_color(int i, char a, t_data *data);
bool	i_is_zero_cmp(int i, char *arg, t_data *data);
bool	i_isnt_zero_cmp(int i, char *arg, t_data *data);
bool	check_fl_cel_error(char a);
//cheking player (N,S,W,E)
bool	check_plr(char a);
//checking spaces and tabs
bool	check_s_t(char a, int check);

//error
void	ft_error(t_data *data, char *error);
//cleaning
void	cleaning(t_data *data);
void	free_array(char **array);

#endif