/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_deco.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:01 by averon            #+#    #+#             */
/*   Updated: 2022/12/01 16:06:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pars_deco(char *path, t_data *data)
{
	if (path[0] == 'N' && path[1] == 'O')
		data->map.check_n += get_path_text(path, 0, data);
	else if (path[0] == 'S' && path[1] == 'O')
		data->map.check_s += get_path_text(path, 1, data);
	else if (path[0] == 'W' && path[1] == 'E')
		data->map.check_w += get_path_text(path, 2, data);
	else if (path[0] == 'E' && path[1] == 'A')
		data->map.check_e += get_path_text(path, 3, data);
	else if (path[0] == 'C')
		data->map.check_c += get_color_ceil(path, data);
	else if (path[0] == 'F')
		data->map.check_f += get_color_floor(path, data);
	else if (ctrl_flag(data) && (!ctrl_empty_line(path)))
		data->map.read_map = 1;
	else if ((!ctrl_empty_line(path)) && data->map.read_map == 0)
		error_print("Error:\nMap not opened. Texture or color issue!");
}

int	get_path_text(char *path, int index, t_data *data)
{
	char	**temp;
	int		i;
	int		fd;

	i = -1;
	if (!path || path[2] != ' ')
	{
		error_print("Error:\nTexture or color issue!");
		return (0);
	}
	temp = ft_split(path, ' ');
	temp[1][ft_strlen(temp[1]) - 1] = '\0';
	if (!temp[1] || temp[2])
		error_print("Erreur:\nTexture not found!");
	data->text[index].name = ft_strdup(temp[1]);
	fd = open (data->text[index].name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (temp[++i])
		free (temp[i]);
	free (temp);
	return (1);
}

int	get_color_ceil(char *path, t_data *data)
{
	char	**temp;
	char	**temp2;
	int		i;

	i = -1;
	temp = ft_split(path, ' ');
	if (!temp[1] || temp[2])
		error_print("Error:\nCeiling color not found!");
	temp2 = ft_split (temp[1], ',');
	if (!temp2[2] || temp2[3])
		error_print("Error:\nCeiling color not found!");
	data->r_ceil = ft_atoi(temp2[0]);
	data->g_ceil = ft_atoi(temp2[1]);
	data->b_ceil = ft_atoi(temp2[2]);
	if (!ctrl_color(data->r_ceil, data->g_ceil, data->b_ceil))
		error_print("Error:\nCeiling color not found!");
	while (temp[++i])
		free(temp[i]);
	free (temp);
	i = -1;
	while (temp2[++i])
		free(temp2[i]);
	free (temp2);
	return (1);
}

int	get_color_floor(char *path, t_data *data)
{
	char	**temp;
	char	**temp2;
	int		i;

	i = -1;
	temp = ft_split(path, ' ');
	if (!temp[1] || temp[2])
		error_print("Error:\nFloor color not found!");
	temp2 = ft_split (temp[1], ',');
	if (!temp2[2] || temp2[3])
		error_print("Error:\nFloor color not found!");
	data->r_floor = ft_atoi(temp2[0]);
	data->g_floor = ft_atoi(temp2[1]);
	data->b_floor = ft_atoi(temp2[2]);
	if (!ctrl_color(data->r_floor, data->g_floor, data->b_floor))
		error_print("Error:\nFloor color not found!");
	while (temp[++i])
		free(temp[i]);
	free (temp);
	i = -1;
	while (temp2[++i])
		free(temp2[i]);
	free (temp2);
	return (1);
}
