/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:28:23 by averon            #+#    #+#             */
/*   Updated: 2022/11/28 19:13:20 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ctrl_flag(t_data *data)
{
	if (data->map.check_n == 0 || data->map.check_s == 0 \
		|| data->map.check_w == 0 || data->map.check_e == 0 \
		|| data->map.check_c == 0 || data->map.check_f == 0)
		return (0);
	return (1);
}

int	test_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
	i++;
	}
	return (0);
}

int	test_tab_int(int *tab, t_map map)
{
	int	i;

	i = 0;
	while (i < map.cols)
	{
		if (tab[i] > 1 || tab [i] < -1)
		{
			printf ("***i:[%d\n]", tab[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ctrl_color(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}
