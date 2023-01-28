/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:56:53 by areheman          #+#    #+#             */
/*   Updated: 2022/12/05 11:41:03 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	img_mini_pix_put(t_data *game, int x, int y, char *add)
{
	char	*pixel;
	int		i;

	i = game->mini.bpp - 8;
	pixel = add + (y * game->mini.size_line + x * \
		(game->mini.bpp / 8));
	while (i >= 0)
	{
		if (game->mini.endian != 0)
			*pixel++ = (game->mini.color >> i) & 0xFF;
		else
			*pixel++ = (game->mini.color >> (game->mini.bpp - 8 - i)) & 0xFF;
				i -= 8;
	}
}

void	draw_mini_map(t_data *data)
{
	int	unt;
	int	x;
	int	y;

	x = -1;
	unt = data->mini.unt;
	data->mini.mini_add = mlx_get_data_addr(data->mini.mini_img, \
		&(data->mini.bpp), &(data->mini.size_line), &(data->mini.endian));
	while (++x < data->mini.w_mini)
	{
			y = -1;
		while (++y < data->mini.h_mini)
		{
			if (data->map_int[x / unt][y / unt] > 0)
				data->mini.color = 0x5EEC3B;
			else if (data->map_int[x / unt][y / unt] == 0)
				data->mini.color = 0x666666;
			else
				data->mini.color = data->color_sky;
			img_mini_pix_put(data, x, y, data->mini.mini_add);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->mini.mini_img, 0, 0);
}

void	draw_mini_player(t_data *data)
{
	int	x;
	int	y;
	int	unt;

	y = 0;
	unt = data->mini.unt;
	data->mini.player.x = data->player.pos.x * unt;
	data->mini.player.y = data->player.pos.y * unt;
	data->mini.pl_add = mlx_get_data_addr(data->mini.pl_img, \
		&(data->mini.bpp), &(data->mini.size_line), &(data->mini.endian));
	while (y < 2)
	{
		x = 0;
		while (x < 2)
		{
			data->mini.color = 0xE8490F;
			img_mini_pix_put(data, x, y, data->mini.pl_add);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, \
		data->mini.pl_img, data->mini.player.x, data->mini.player.y);
}

void	set_mini_map_player(t_data *data)
{
	int	unt;

	if (data->map.lines > data->map.cols)
		unt = 100 / data->map.lines;
	else
		unt = 100 / data->map.cols;
	data->mini.w_mini = unt * data->map.cols;
	data->mini.h_mini = unt * data->map.lines;
	data->mini.player.x = data->player.pos.x * unt;
	data->mini.player.y = data->player.pos.y * unt;
	data->mini.mini_img = mlx_new_image(data->mlx, \
			data->mini.w_mini, data->mini.h_mini);
	data->mini.pl_img = mlx_new_image(data->mlx, 2, 2);
	data->mini.unt = unt;
}

void	draw_mini_map_player(t_data *data)
{
	draw_mini_map(data);
	draw_mini_player(data);
}
