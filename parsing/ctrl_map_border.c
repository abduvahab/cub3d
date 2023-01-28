/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_map_border.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:29:26 by averon            #+#    #+#             */
/*   Updated: 2022/11/28 19:13:01 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ctrl_map_border(t_data *data)
{
	if (ctrl_map_top(data) == 0)
		return (0);
	if (ctrl_map_bottom(data) == 0)
		return (0);
	if (ctrl_map_left(data) == 0)
		return (0);
	if (ctrl_map_right(data) == 0)
		return (0);
	return (1);
}

int	ctrl_map_top(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map_char[0][i])
	{
		if (data->map.map_char[0][i] == '1' || data->map.map_char[0][i] == ' ')
			i++;
		else if (test_char(data->map.map_char[0][i], "0NSEW"))
			return (0);
	}
	return (1);
}

int	ctrl_map_bottom(t_data *data)
{
	int	i;
	int	end;

	i = 0;
	end = last_line_pos(data) - 1;
	while (data->map.map_char[end][i])
	{
		if (data->map.map_char[end][i] == '1'
			|| data->map.map_char[end][i] == ' ')
			i++;
		else if (test_char(data->map.map_char[end][i], "0NSEW"))
			return (0);
	}
	return (1);
}

int	ctrl_map_left(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map_char[i])
	{
		if (data->map.map_char[i][0] == '1' || data->map.map_char[i][0] == ' ')
			i++;
		else if (test_char(data->map.map_char[i][0], "0NSEW"))
			return (0);
	}
	return (1);
}

int	ctrl_map_right(t_data *data)
{
	int	i;
	int	end;

	i = 0;
	while (data->map.map_char[i])
	{
		end = ft_strlen(data->map.map_char[i]) - 1;
		if (data->map.map_char[i][end] == '1'
			|| data->map.map_char[i][end] == ' ')
			i++;
		else if (test_char(data->map.map_char[i][end], "0NSEW"))
			return (0);
	}
	return (1);
}
