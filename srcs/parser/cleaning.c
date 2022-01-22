/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <fkenned@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:34:16 by fkenned           #+#    #+#             */
/*   Updated: 2022/01/22 18:21:05 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	cleaning(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->repfile)
		free(data->repfile);
	if (data->map)
		free_array(data->map);
}
