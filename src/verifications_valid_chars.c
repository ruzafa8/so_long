/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications_valid_chars.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:33:55 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 18:43:41 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_value	*sl_validate_chars(char *map, size_t width, size_t height)
{
	t_value	*parsed_map;

	if (!verify_valid_chars(map))
		return ((t_value *) sl_error("El mapa tiene caracteres inválidos."));
	parsed_map = ctov(map, width, height);
	if (!parsed_map)
		return ((t_value *) sl_error("Problema de memoria."));
	return (parsed_map);
}
