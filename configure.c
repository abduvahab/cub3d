/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:46:51 by areheman          #+#    #+#             */
/*   Updated: 2022/12/01 15:30:52 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	get_direction_n_s(t_data *data)
{
	if (data->map.player_start_dir_char == 'N')
	{
		data->player.dir.x = 0.0;
		data->player.dir.y = -1.0;
		data->player.plan.x = -0.66;
		data->player.plan.y = 0.0;
	}
	else if (data->map.player_start_dir_char == 'S')
	{
		data->player.dir.x = 0.0;
		data->player.dir.y = 1.0;
		data->player.plan.x = 0.66;
		data->player.plan.y = 0.0;
	}
}

static void	get_direction_e_w(t_data *data)
{	
	if (data->map.player_start_dir_char == 'E')
	{
		data->player.dir.x = 1.0;
		data->player.dir.y = 0.0;
		data->player.plan.x = 0.0;
		data->player.plan.y = 0.66;
	}
	else if (data->map.player_start_dir_char == 'W')
	{
		data->player.dir.x = -1.0;
		data->player.dir.y = 0.0;
		data->player.plan.x = 0.0;
		data->player.plan.y = 0.66;
	}
}

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	ft_player_conf(t_data *data)
{
	data->player.mapx = data->map.player_start_pos_x;
	data->player.mapy = data->map.player_start_pos_y;
	data->player.pos.x = (double)data->map.player_start_pos_x;
	data->player.pos.y = (double)data->map.player_start_pos_y;
	data->player.m_speed = 0.2;
	data->player.r_speed = 0.1;
	get_direction_n_s(data);
	get_direction_e_w(data);
	data->color_floor = (int)create_rgb(data->r_floor, \
			data->g_floor, data->b_floor);
	data->color_sky = (int)create_rgb(data->r_ceil, data->g_ceil, data->b_ceil);
}

void	text_conf(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->text[i].img = mlx_xpm_file_to_image(data->mlx, \
			data->text[i].name, &(data->text[i].t_w), &(data->text[i].t_h));
		data->text[i].add = (int *) mlx_get_data_addr(data->text[i].img, \
					&(data->text[i].pixel_bits), \
					&(data->text[i].line_bytes), &(data->text[i].endian));
		data->text[i].line_bytes /= 4;
		i++;
	}
}
