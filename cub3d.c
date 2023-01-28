/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:59:59 by areheman          #+#    #+#             */
/*   Updated: 2022/12/02 17:01:45 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, S_WIDTH, S_HEIGHT, " cub3d");
	data->scr.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	data->scr.add = mlx_get_data_addr(data->scr.img, \
		&(data->scr.bpp), &(data->scr.size_line), &(data->scr.endian));
	ft_player_conf(data);
	text_conf(data);
	set_mini_map_player(data);
}

int	my_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_destroy_window(data->mlx, data->win);
	while (i < data->map.cols)
		free(data->map_int[i++]);
	free(data->map_int);
	ft_free(data->map.map_char);
	free(data->input_str);
	free(data->mlx);
	while (j < 4)
	{	
		free(data->text[j].name);
		j++;
	}
	exit(1);
}

int	main_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ray_casting(data);
	draw_mini_map_player(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ctrl_file(argc, argv, &data);
	init_data_map(&data);
	pars_all(&data);
	ctrl_emtpy_map(&data);
	get_map_size(&data);
	ctrl_map(&data);
	get_tab_int(&data);
	init_data(&data);
	ray_casting(&data);
	draw_mini_map_player(&data);
	mlx_hook(data.win, 17, 1l << 2, my_close, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
