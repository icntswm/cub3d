/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <fkenned@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:34:50 by fkenned           #+#    #+#             */
/*   Updated: 2022/01/22 18:21:21 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parser(char *file, t_data *data)
{
	int		fd_file;

	init_data(data);
	if (!check_extension(file, 0))
		ft_error(data, "ext");
	fd_file = open(file, O_RDONLY, 0644);
	if (fd_file == -1)
		ft_error(data, "open_file");
	else
	{
		reaplace_file(data, fd_file);
		close(fd_file);
	}
	handling_data(data);
}
