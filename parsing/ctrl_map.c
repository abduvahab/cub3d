/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:31:51 by averon            #+#    #+#             */
/*   Updated: 2022/11/29 21:36:38 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ctrl_map(t_data *data)
{
	if (ctrl_map_char(data) == 0)
		error_print("Error:\nUnauthorized char in map !");
	if (ctrl_map_border(data) == 0)
		error_print("Error:\nMap not closed!");
	if (ctrl_map_space(data) == 0)
		error_print("Error:\nEmpty space inside the map !");
	if (ctrl_one_player(data) == 0)
		error_print("Error:\nNumber of players is not one!");
	return (0);
}

int	ctrl_map_char(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (data->map.map_char[++i])
	{
		while (data->map.map_char[i][++j])
		{
			if (test_char(data->map.map_char[i][j], " \t01NSEW") == 0)
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	ctrl_map_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < data->map.lines - 1)
	{
		while (++j < (int)(ft_strlen(data->map.map_char[i]) - 1))
		{
			if (test_char(data->map.map_char[i][j], "0NSEW"))
			{
				if (ctrl_blank(data->map.map_char[i + 1][j]) == 0 \
					|| ctrl_blank(data->map.map_char[i + 1][j + 1]) == 0 \
					|| ctrl_blank(data->map.map_char[i + 1][j - 1]) == 0 \
					|| ctrl_blank(data->map.map_char[i][j + 1]) == 0 \
					|| ctrl_blank(data->map.map_char[i][j - 1]) == 0 \
					|| ctrl_blank(data->map.map_char[i - 1][j]) == 0 \
					|| ctrl_blank(data->map.map_char[i - 1][j + 1]) == 0 \
					|| ctrl_blank(data->map.map_char[i - 1][j - 1]) == 0)
					return (0);
			}			
		}
		j = 0;
	}
	return (1);
}

int	ctrl_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (0);
	return (1);
}

int	ctrl_one_player(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.lines)
	{
		data->one_player += char_count(data->map.map_char[i], 'N');
		data->one_player += char_count(data->map.map_char[i], 'E');
		data->one_player += char_count(data->map.map_char[i], 'S');
		data->one_player += char_count(data->map.map_char[i], 'W');
		i++;
	}
	if (data->one_player != 1)
		return (0);
	else
		return (1);
}
