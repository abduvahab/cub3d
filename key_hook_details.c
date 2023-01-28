/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_details.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:09:51 by areheman          #+#    #+#             */
/*   Updated: 2022/11/28 18:57:17 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	key_up_dw(int k, t_data *data)
{
	if (k == W || k == UP)
	{
		if (data->map_int[(int)(data->player.pos.x + data->player.dir.x \
			* data->player.m_speed)][(int)(data->player.pos.y \
			+ data->player.dir.y * data->player.m_speed)] == 0)
		{
			data->player.pos.x += data->player.dir.x * data->player.m_speed;
			data->player.pos.y += data->player.dir.y * data->player.m_speed;
		}
	}
	if (k == S || k == DW)
	{
		if (data->map_int[(int)(data->player.pos.x - data->player.dir.x \
			* data->player.m_speed)][(int)(data->player.pos.y \
				- data->player.dir.y * data->player.m_speed)] == 0)
		{
			data->player.pos.x -= data->player.dir.x * data->player.m_speed;
			data->player.pos.y -= data->player.dir.y * data->player.m_speed;
		}
	}
}

void	key_d(int k, t_data *data)
{
	if (k == D && data->map_int[(int)(data->player.pos.x)] \
			[(int)(data->player.pos.y + data->player.dir.y \
			* data->player.m_speed)] == 0)
	{
		if (data->player.dir.x >= 0 && data->player.dir.y >= 0)
		{
			data->player.pos.x -= data->player.dir.y * data->player.m_speed;
			data->player.pos.y += data->player.dir.x * data->player.m_speed;
		}
		else if (data->player.dir.x >= 0 && data->player.dir.y <= 0)
		{	
			data->player.pos.x -= data->player.dir.y * data->player.m_speed;
			data->player.pos.y += data->player.dir.x * data->player.m_speed;
		}
		else if (data->player.dir.x <= 0 && data->player.dir.y >= 0)
		{
			data->player.pos.x -= data->player.dir.y * data->player.m_speed;
			data->player.pos.y += data->player.dir.x * data->player.m_speed;
		}
		else if (data->player.dir.x <= 0 && data->player.dir.y <= 0)
		{	
			data->player.pos.x -= data->player.dir.y * data->player.m_speed;
			data->player.pos.y += data->player.dir.x * data->player.m_speed;
		}
	}
}

void	key_a(int k, t_data *data)
{
	if (k == A && data->map_int[(int)(data->player.pos.x)] \
			[(int)(data->player.pos.y - data->player.dir.y \
			* data->player.m_speed)] == 0)
	{
		if (data->player.dir.x >= 0 && data->player.dir.y >= 0)
		{
			data->player.pos.x += data->player.dir.y * data->player.m_speed;
			data->player.pos.y -= data->player.dir.x * data->player.m_speed;
		}
		else if (data->player.dir.x >= 0 && data->player.dir.y <= 0)
		{	
			data->player.pos.x += data->player.dir.y * data->player.m_speed;
			data->player.pos.y -= data->player.dir.x * data->player.m_speed;
		}
		else if (data->player.dir.x <= 0 && data->player.dir.y >= 0)
		{	
			data->player.pos.x += data->player.dir.y * data->player.m_speed;
			data->player.pos.y -= data->player.dir.x * data->player.m_speed;
		}
		else if (data->player.dir.x <= 0 && data->player.dir.y <= 0)
		{	
			data->player.pos.x += data->player.dir.y * data->player.m_speed;
			data->player.pos.y -= data->player.dir.x * data->player.m_speed;
		}
	}
}

void	key_rh(t_data *data)
{
	double	old_dir;
	double	old_plan;

	old_dir = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(-data->player.r_speed) \
		- data->player.dir.y * sin(-data->player.r_speed);
	data->player.dir.y = old_dir * sin(-data->player.r_speed) \
		+ data->player.dir.y * cos(-data->player.r_speed);
	old_plan = data->player.plan.x;
	data->player.plan.x = data->player.plan.x * cos(-data->player.r_speed) \
		- data->player.plan.y * sin(-data->player.r_speed);
	data->player.plan.y = old_plan * sin(-data->player.r_speed) \
		+ data->player.plan.y * cos(-data->player.r_speed);
}

void	key_lf(t_data *data)
{
	double	old_dir;
	double	old_plan;

	old_dir = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(data->player.r_speed) \
		- data->player.dir.y * sin(data->player.r_speed);
	data->player.dir.y = old_dir * sin(data->player.r_speed) \
		+ data->player.dir.y * cos(data->player.r_speed);
	old_plan = data->player.plan.x;
	data->player.plan.x = data->player.plan.x * cos(data->player.r_speed) \
		- data->player.plan.y * sin(data->player.r_speed);
	data->player.plan.y = old_plan * sin(data->player.r_speed) \
		+ data->player.plan.y * cos(data->player.r_speed);
}
