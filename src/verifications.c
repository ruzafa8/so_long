/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:34:36 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 17:51:23 by aruzafa-         ###   ########.fr       */
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

/**
 * Verifies that the array uses only valid chars.
 * @param map a map in string to verify.
 * @return 0 if any character has an invalid value.
 * 1 if all the character are valid.
 */
static int	verify_valid_chars(char *map)
{
	size_t	index;

	index = 0;
	while (map[index])
	{
		if (
			map[index] != WALL
			&& map[index] != FLOOR
			&& map[index] != COLLECTIONABLE
			&& map[index] != PLAYER
			&& map[index] != EXIT
		)
		{
			return (0);
		}
		index++;
	}
	return (1);
}

/**
 * Parses a the char map to t_value array map.
 */
static t_value	*ctov(char *map, size_t width, size_t height)
{
	t_value	*res;
	size_t	i;

	res = (t_value *) ft_calloc((width * height) + 1, sizeof(t_value));
	if (!res)
		return (0);
	i = 0;
	while (map[i])
	{
		if (map[i] == '0')
			res[i] = FLOOR;
		else if (map[i] == '1')
			res[i] = WALL;
		else if (map[i] == 'E')
			res[i] = EXIT;
		else if (map[i] == 'P')
			res[i] = PLAYER;
		else
			res[i] = COLLECTIONABLE;
		i++;
	}
	res[i] = 0;
	return (res);
}

t_data	*sl_verify_map(char *map, size_t width, size_t height)
{
	t_data	*data;
	size_t	count;

	if (!verify_valid_chars(map))
		return ((t_data *) sl_error("El mapa tiene caracteres inválidos."));
	data = (t_data *) ft_calloc(1, sizeof(t_data));
	data->map = ctov(map, width, height);
	if (!data->map)
		return (sl_free_data(&data), (t_data *) sl_error("Problema de memoria."));
	data->width = width;
	data->height = height;
	if (verify_wall(data) == 0)
		return (sl_free_data(&data), (t_data *) sl_error("El borde no está relleno de muros."));
	data->player = (t_position *) ft_calloc(1, sizeof(t_position));
	count = count_value(data, PLAYER, &(data->player->x), &(data->player->y));
	if (count == 0)
		return (sl_free_data(&data), (t_data *) sl_error("No se ha encontrado al jugador."));
	if (count > 1)
		return (sl_free_data(&data), (t_data *) sl_error("Hay más de 1 jugador."));
	data->exit = (t_position *) ft_calloc(1, sizeof(t_position));
	count = count_value(data, EXIT,  &(data->exit->x), &(data->exit->y));
	if (count == 0)
		return (sl_free_data(&data), (t_data *) sl_error("No se ha encontrado la salida."));
	if (count > 1)
		return (sl_free_data(&data), (t_data *) sl_error("Hay más de 1 salida."));
	data->num_col = count_value(data, COLLECTIONABLE, 0, 0);
	if (data->num_col == 0)
		return (sl_free_data(&data), (t_data *) sl_error("No hay ningún coleccionable."));
	return (data);
}