/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:04:24 by areheman          #+#    #+#             */
/*   Updated: 2022/12/01 10:16:42 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	find_delta_distance(t_data *data, int x)
{
	data->ray.camera = 2 * x / (double)(S_WIDTH) - 1;
	data->ray.ray_dir.x = data->player.dir.x + \
			(data->player.plan.x) * data->ray.camera;
	data->ray.ray_dir.y = data->player.dir.y + \
			(data->player.plan.y) * data->ray.camera;
	data->ray.mapx = (int)data->player.pos.x;
	data->ray.mapy = (int)data->player.pos.y;
	if (data->ray.ray_dir.x == 0)
		data->ray.delta_dis.x = 1e30;
	else
		data->ray.delta_dis.x = fabs(1 / data->ray.ray_dir.x);
	if (data->ray.ray_dir.y == 0)
		data->ray.delta_dis.y = 1e30;
	else
		data->ray.delta_dis.y = fabs(1 / data->ray.ray_dir.y);
}

void	find_next_side(t_data *data)
{
	if (data->ray.ray_dir.x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dis.x = (data->player.pos.x \
			- data->ray.mapx) * data->ray.delta_dis.x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dis.x = (data->ray.mapx \
			+ 1.0 - data->player.pos.x) * data->ray.delta_dis.x;
	}
	if (data->ray.ray_dir.y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dis.y = (data->player.pos.y \
			- data->ray.mapy) * data->ray.delta_dis.y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dis.y = (data->ray.mapy \
			+ 1.0 - data->player.pos.y) * data->ray.delta_dis.y;
	}
}

void	check_hit(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.side_dis.x < data->ray.side_dis.y)
		{
			data->ray.side_dis.x += data->ray.delta_dis.x;
			data->ray.mapx += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dis.y += data->ray.delta_dis.y;
			data->ray.mapy += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map_int[data->ray.mapx][data->ray.mapy] > 0)
			hit = 1;
	}
}

void	find_side_distance(t_data *data, int x)
{
	find_delta_distance(data, x);
	find_next_side(data);
	check_hit(data);
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.side_dis.x - data->ray.delta_dis.x);
	else
		data->ray.perpwalldist = (data->ray.side_dis.y - data->ray.delta_dis.y);
	find_start_end_point(data);
}

void	ray_casting(t_data *data)
{
	int	x;

	x = 0;
	while (x < S_WIDTH)
	{
		find_side_distance(data, x);
		set_texture(data);
		draw_screen(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->scr.img, 0, 0);
}
