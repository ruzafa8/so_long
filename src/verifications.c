/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:34:36 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/18 14:41:40 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Verifies that the map has got wall in the borders.
 * @param map a map in string to verify.
 * @return 0 if any character in border has not got wall.
 * 1 if all is correct.
 */
static int  verify_wall(t_data *data)
{
    size_t  x;
    size_t  y;

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
 * Count the number of ocurrences of the value in the map and returns the last ocurrence of it.
 * @param data the map.
 * @param value the value to count.
 * @param x sets the position x of the last ocurrence of the value found.
 * @param y sets the position y of the last ocurrence of the founded value
 * @returns the number of ocurrences of the value in the map.
 */
static size_t   count_value(t_data *data, t_value value, int *pos_x, int *pos_y)
{
    size_t  count;
    size_t  x;
    size_t  y;

    count = 0;
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (sl_get_position(data, x, y) == value)
            {
                *pos_x = x;
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
static int  verify_valid_chars(char *map)
{
    size_t  index;

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

t_data  *sl_verify_map(char *map, size_t width, size_t height)
{
    t_data  *data;

    if (!verify_valid_chars(map))
        return ((t_data *) sl_print_error("Error\nEl mapa tiene caracteres inválidos."));
    data = (t_data *) ft_calloc(1, sizeof(data));
    data->map = (t_value *) map;
    data->width = width;
    data->height = height;
    data->player = 0;
    data->exit = 0;
    data->num_col = 0;
    if (verify_wall(data) == 0)
        return (sl_free_map(&data), (t_data *) sl_print_error("Error\nEl borde no está relleno de muros."));
    data->player = (t_position *) ft_calloc(1, sizeof(t_position));
    if (count_value(data, PLAYER, &(data->player->x), &(data->player->y)) != 1)
        return (sl_free_map(&data), (t_data *) sl_print_error("Error\nNo se ha encontrado al jugador."));
    data->player = (t_position *) ft_calloc(1, sizeof(t_position));
    if (count_value(data, EXIT,  &(data->exit->x), &(data->exit->y)) != 1)
        return (sl_free_map(&data), (t_data *) sl_print_error("Error\nNo se ha encontrado la salida."));
    data->num_col = count_value(data, COLLECTIONABLE, 0, 0);
    if (data->num_col == 0)
        return (sl_free_map(&data), (t_data *) sl_print_error("Error\nNo hay ningún coleccionable."));
    return data;
}