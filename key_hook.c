/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averon <averon@student.42Mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:51:34 by averon            #+#    #+#             */
/*   Updated: 2022/11/28 18:55:02 by averon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	key_hook(int k, t_data *data)
{
	if (k == W || k == UP)
		key_up_dw(k, data);
	if (k == S || k == DW)
		key_up_dw(k, data);
	if (k == D)
		key_d(k, data);
	if (k == A)
		key_a(k, data);
	if (k == LF)
		key_rh(data);
	if (k == RH)
		key_lf(data);
	if (k == ESC)
		my_close(data);
	return (0);
}
