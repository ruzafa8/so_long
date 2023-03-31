/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:50:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/31 16:16:31 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_floor(t_data *data)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			sl_print_texture(data, FLOOR, x, y);
			x++;
		}
		y++;
	}
}

void	load_player_images(t_data *data)
{
	size_t	i;

	i = 1;
	while (i < 16)
	{
		mlx_image_to_window(data->mlx, data->images->player[i], 0, 0);
		data->images->player[i]->instances[0].enabled = 0;
		i++;
	}
}

void	sl_print_map(t_data *data)
{
	size_t		x;
	size_t		y;
	t_value		value;

	print_floor(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			value = sl_get_position(data, x, y);
			if (value != FLOOR)
				sl_print_position(data, x, y);
			x++;
		}
		y++;
	}
	load_player_images(data);
}
