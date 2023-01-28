/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_text2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:22:36 by areheman          #+#    #+#             */
/*   Updated: 2022/12/02 16:57:46 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	img_pix_put(t_data *game, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = game->scr.bpp - 8;
	pixel = game->scr.add + (y * game->scr.size_line + x * \
		(game->scr.bpp / 8));
	while (i >= 0)
	{
		if (game->scr.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (game->scr.bpp - 8 - i)) & 0xFF;
				i -= 8;
	}
}

void	my_pixel_put_screen(t_data *data, int y, int j)
{
	int	tex_y;

	if (y >= 0 && y < data->scr.start)
	{
		data->scr.color = data->color_sky;
		img_pix_put(data, j, y, data->scr.color);
	}
	if (y >= data->scr.start && y < data->scr.end)
	{
		tex_y = (int)data->text->tex_pos & (data->text->t_h - 1);
		data->text->tex_pos += data->text->step;
		data->scr.color = data->text[data->text->num].add[(data->\
			text[data->text->num].line_bytes * tex_y + data->text->tex_x)];
		img_pix_put(data, j, y, data->scr.color);
	}
	if (y >= data->scr.end && y < S_HEIGHT)
	{
		data->scr.color = data->color_floor;
		img_pix_put(data, j, y, data->scr.color);
	}	
}
