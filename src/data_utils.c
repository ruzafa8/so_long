/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:22:52 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 15:14:13 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    sl_free_map(t_data **data)
{
    if (*data)
    {
        if ((*data)->map)
            free((*data)->map);
        if ((*data)->player)
            free((*data)->player);
        if ((*data)->exit)
            free((*data)->exit);
        free(*data);
    }
}

t_value sl_get_position(t_data *data, size_t x, size_t y)
{
    if (x < 0 || x >= data->width)
        return (INVALID);
    if (y < 0 || y >= data->height)
        return (INVALID);
    return data->map[(x * data->width) + y];
}