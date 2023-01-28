/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:47:26 by averon            #+#    #+#             */
/*   Updated: 2022/11/30 10:19:11 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_tab_int(t_data *data)
{
	int	i;
	int	j;

	init_tab_int(data);
	j = 0;
	while (j < data->map.lines)
	{
		i = 0;
		while (data->map.map_char[j][i] == 9 || data->map.map_char[j][i] == 32)
		{	
			data->map_int[i][j] = -1;
			i++;
		}
		while (i < data->map.cols && data->map.map_char[j][i])
		{	
			fill_tab_int(data, i, j);
			i++;
		}
		while (i < data->map.cols)
		{	
			data->map_int[i][j] = -1;
			i++;
		}
		j++;
	}
}

void	init_tab_int(t_data *data)
{
	int	i;

	i = 0;
	data->map_int = malloc (sizeof(int *) * (data->map.cols));
	if (data->map_int == NULL)
		exit(0);
	while (i < data->map.cols)
	{
		data->map_int [i] = malloc(sizeof(int) * data->map.lines);
		if (data->map_int[i] == NULL)
			exit(0);
		i++;
	}
}

void	fill_tab_int(t_data *data, int i, int j)
{
	if (data->map.map_char[j][i] == '0'
		|| data->map.map_char[j][i] == '1')
		data->map_int[i][j] = (data->map.map_char[j][i] - 48);
	else if ((!test_char(data->map.map_char[j][i], "01NSEW")))
		data->map_int[i][j] = -1;
	else if (test_char(data->map.map_char[j][i], "NSEW"))
		set_player(data, i, j);
}

void	set_player(t_data *data, int i, int j)
{
	data->map.player_start_dir_char = data->map.map_char[j][i];
	data->map.player_start_pos_x = i + 1;
	data->map.player_start_pos_y = j + 1;
	data->map_int[i][j] = 0;
}
