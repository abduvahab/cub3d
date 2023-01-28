/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_file_and_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:58:18 by averon            #+#    #+#             */
/*   Updated: 2022/11/29 21:35:11 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ctrl_file(int argc, char **argv, t_data *data)
{
	int	filename_len;

	if (argc != 2)
		error_print("Error:\nenter a map file !");
	filename_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][filename_len - 4], ".cub", 4))
		error_print("Error:\nfilename doesn't include .cub extension !");
	data->map_path = ft_strdup(argv[1]);
}

void	init_data_map(t_data *data)
{
	data->map.check_n = 0;
	data->map.check_s = 0;
	data->map.check_e = 0;
	data->map.check_w = 0;
	data->map.check_c = 0;
	data->map.check_f = 0;
	data->map.read_map = 0;
	data->map.lines = 0;
	data->map.cols = 0;
	data->one_player = 0;
}
