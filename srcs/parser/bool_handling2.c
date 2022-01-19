/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_handling2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <fkenned@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:55:34 by fkenned           #+#    #+#             */
/*   Updated: 2022/01/19 18:55:24 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_fl_cel_error(char a)
{
	return (a != ' ' && a != '\t' && !(a >= '0' && a <= '9')
		&& a != ',' && a != '\n');
}

bool	check_plr(char a)
{
	return (a == 'N' || a == 'S' || a == 'W' || a == 'E');
}

bool	check_s_t(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}

bool    check_cub(char *str)
{
    int i;

    i = ft_strlen(str) - 1;
    if (str[i] == 'm' && str[i - 1] == 'p' && str[i - 2] == 'x' && str[i - 3] == '.')
        return (true);
    return (false);
}