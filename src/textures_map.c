/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:50:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/27 18:29:48 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_print_map(t_data *data)
{
	size_t		x;
	size_t		y;
	t_value		value;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			value = sl_get_position(data, x, y);
			if (value != FLOOR)
				sl_print_texture(data, FLOOR, x, y);
			sl_print_position(data, x, y);
			x++;
		}
		y++;
	}
}
