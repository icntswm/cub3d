#include "cub3d.h"

void	joincolor(char **color, char *add)
{
	char	*save;

	save = *color;
	if (save == NULL)
	{
		*color = ft_strjoin(save, "#");
		free(save);
		save = *color;
		*color = ft_strjoin(save, add);
	}
	else
		*color = ft_strjoin(save, add);
	free(save);
}

void	hexsys(long long n, char **color)
{
	char	*itoa_conv;

	itoa_conv = NULL;
	if (n > 15)
		hexsys(n / 16, color);
	if ((n % 16) >= 0 && (n % 16) <= 9)
	{
		itoa_conv = ft_itoa(n % 16);
		joincolor(color, itoa_conv);
		free(itoa_conv);
	}
	if ((n % 16) == 10)
		joincolor(color, "A");
	if ((n % 16) == 11)
		joincolor(color, "B");
	if ((n % 16) == 12)
		joincolor(color, "C");
	if ((n % 16) == 13)
		joincolor(color, "D");
	if ((n % 16) == 14)
		joincolor(color, "E");
	if ((n % 16) == 15)
		joincolor(color, "F");
}

void	rgb_less_ten(char **color, int num)
{
	char	*itoa_conv;
	char	*save;

	if (num < 10)
		itoa_conv = ft_itoa(num);
	else
		itoa_conv = ft_strdup((char [1]){55 + num});
	save = itoa_conv;
	itoa_conv = ft_strjoin("0", save);
	free(save);
	joincolor(color, itoa_conv);
	free(itoa_conv);
}

int	process_hex(int num, char **color, char **hex)
{
	if (num >= 0 && num < 16)
		rgb_less_ten(color, num);
	else if (num < 0 || num > 255)
	{
		if (*hex)
			free(*hex);
		*hex = *color;
		return (1);
	}
	else
		hexsys(num, color);
	return (0);
}

int	make_hex(char **hex)
{
	int		i;
	char	*color;
	char	**hex_array;

	i = 0;
	hex_array = ft_split(*hex, ',');
	color = NULL;
	while (hex_array[i])
	{
		if (process_hex(ft_atoi(hex_array[i++]), &color, hex))
		{
			free_array(hex_array);
			return (1);
		}
	}
	if (*hex)
		free(*hex);
	*hex = color;
	free_array(hex_array);
	if (i != 3)
		return (2);
	return (0);
}
