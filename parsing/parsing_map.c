/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:43:32 by averon            #+#    #+#             */
/*   Updated: 2022/11/30 10:17:46 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pars_all(t_data *data)
{
	char	*temp;

	data->fd = pars_open_map(data);
	data->input_str = get_next_line (data->fd);
	while (data->input_str)
	{
		if (data->map.read_map == 0)
			pars_deco(data->input_str, data);
		if (data->map.read_map == 1)
		{
			if (ctrl_empty_line(data->input_str))
				error_print("Error: map including empty line !");
			if (data->map.lines == 0)
				temp = ft_strdup(data->input_str);
			else
				temp = ft_strjoin(temp, data->input_str);
			data->map.lines += 1;
		}
		free(data->input_str);
		data->input_str = get_next_line(data->fd);
	}
	free(data->input_str);
	close (data->fd);
	data->map.map_char = ft_split(temp, '\n');
	free(temp);
}

int	pars_open_map(t_data *data)
{
	data->fd = open(data->map_path, O_RDONLY);
	if (data->fd == -1)
	{
		error_print("Error: can't open file !");
		return (data->fd);
	}
	free(data->map_path);
	return (data->fd);
}

void	get_map_size(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.lines)
	{
		if (data->map.cols < (int)ft_strlen(data->map.map_char[i]))
			data->map.cols = ft_strlen(data->map.map_char[i]);
		i++;
	}
}

void	ctrl_emtpy_map(t_data *data)
{
	if (data->map.map_char[0] == NULL)
		error_print("Error: the map is empty!");
}

int	ctrl_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
