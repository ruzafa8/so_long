/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:34:36 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/27 19:34:11 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Verifies that the map has got wall in the borders.
 * @param map a map in string to verify.
 * @return 0 if any character in border has not got wall.
 * 1 if all is correct.
 */
static int	verify_wall(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if ((x == 0 || y == 0 || x == data->width - 1
					|| y == data->height - 1)
				&& sl_get_position(data, x, y) != WALL)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/**
 * Count the number of ocurrences of the value in the map
 * and returns the last ocurrence of it.
 * @param data the map.
 * @param value the value to count.
 * @param x sets the position x of the last ocurrence of the value found.
 * @param y sets the position y of the last ocurrence of the founded value
 * @returns the number of ocurrences of the value in the map.
 */
static size_t	count_value(t_data *data, t_value value, int *pos_x, int *pos_y)
{
	size_t	count;
	size_t	x;
	size_t	y;

	count = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (sl_get_position(data, x, y) == value)
			{
				if (pos_x)
					*pos_x = x;
				if (pos_y)
					*pos_y = y;
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

static t_data	*verify_map_error(t_data **data, char *error)
{
	sl_free_data(data);
	sl_error(error);
	return (0);
}

t_data	*sl_verify_map(char *map, size_t width, size_t height)
{
	t_data	*data;

	data = (t_data *) ft_calloc(1, sizeof(t_data));
	data->map = sl_validate_chars(map, width, height);
	if (!data->map)
		return (sl_free_data(&data), (t_data *) 0);
	data->width = width;
	data->height = height;
	if (verify_wall(data) == 0)
		return (verify_map_error(&data, "El borde no está relleno de muros."));
	data->player = (t_position *) ft_calloc(1, sizeof(t_position));
	if (count_value(data, PLAYER, &(data->player->x), &(data->player->y)) != 1)
		return (verify_map_error(&data, "Debe de haber 1 y solo 1 jugador."));
	data->exit = (t_position *) ft_calloc(1, sizeof(t_position));
	if (count_value(data, EXIT, &(data->exit->x), &(data->exit->y)) != 1)
		return (verify_map_error(&data, "Debe de haber 1 solo 1 salida."));
	data->num_col = count_value(data, COLLECTIONABLE, 0, 0);
	if (data->num_col == 0)
		return (verify_map_error(&data, "No hay ningún coleccionable."));
	return (data);
}
