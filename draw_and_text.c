/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:03:17 by averon            #+#    #+#             */
/*   Updated: 2022/12/01 15:51:09 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	draw_screen(t_data *data, int x)
{
	int	y;
	int	j;

	y = -1;
	while (++y < S_HEIGHT)
	{
		j = x;
		if (data->map.player_start_dir_char != 'E')
			j = (S_WIDTH - 1) - x;
		my_pixel_put_screen(data, y, j);
	}
}

void	get_num_texture(t_data *data)
{
	if (data->ray.side == 0 && data->ray.ray_dir.x < 0)
		data->text->num = 0;
	if (data->ray.side == 1 && data->ray.ray_dir.x < 0)
	{
		if (data->ray.ray_dir.y < 0)
			data->text->num = 1;
		if (data->ray.ray_dir.y >= 0)
			data->text->num = 3;
	}
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		data->text->num = 2;
	if (data->ray.side == 1 && data->ray.ray_dir.x > 0)
	{
		if (data->ray.ray_dir.y < 0)
			data->text->num = 1;
		if (data->ray.ray_dir.y >= 0)
			data->text->num = 3;
	}
}

void	set_texture(t_data *data)
{
	get_num_texture(data);
	if (data->ray.side == 0)
		data->text->wallx = data->player.pos.y \
			+ data->ray.perpwalldist * data->ray.ray_dir.y;
	else
		data->text->wallx = data->player.pos.x \
			+ data->ray.perpwalldist * data->ray.ray_dir.x;
	data->text->wallx -= floor(data->text->wallx);
	data->text->tex_x = (int)(data->text->wallx * (double)(data->text->t_w));
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		data->text->tex_x = data->text->t_w - data->text->tex_x -1;
	if (data->ray.side == 1 && data->ray.ray_dir.x < 0)
		data->text->tex_x = data->text->t_w - data->text->tex_x -1;
	data->text->step = 1.0 * data->text->t_h / data->scr.lineheight;
	data->text->tex_pos = (data->scr.start - S_HEIGHT / 2 \
		+ data->scr.lineheight / 2) * data->text->step;
}

void	find_start_end_point(t_data *data)
{
	data->scr.lineheight = (int)(S_HEIGHT / data->ray.perpwalldist);
	data->scr.start = -data->scr.lineheight / 2 + (S_HEIGHT / 2);
	if (data->scr.start < 0)
		data->scr.start = 0;
	data->scr.end = data->scr.lineheight / 2 + (S_HEIGHT / 2);
	if (data->scr.end < 0)
		data->scr.end = 0;
}
