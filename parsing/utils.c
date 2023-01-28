/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:11:15 by averon            #+#    #+#             */
/*   Updated: 2022/11/25 14:49:35 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_print(char *str)
{
	ft_printf("\033[1;31m%s\n", str);
	exit (0);
}

int	last_line_pos(t_data *data)
{
	int	i;
	int	pos;

	i = 0;
	while (data->map.map_char[i])
		i++;
	pos = i;
	return (pos);
}

int	char_count(char *str, char c)
{
	int	x;
	int	nb_char;

	x = 0;
	nb_char = 0;
	while (str[x] != '\0' && ft_isprint(str[x]) != 0)
	{
		if (str[x] == c)
			nb_char++;
		x++;
	}
	return (nb_char);
}
