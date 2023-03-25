/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:22:52 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 18:14:13 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_data(t_data **data)
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

t_value	sl_get_position(t_data *data, size_t x, size_t y)
{
	if (x < 0 || x >= data->width)
		return (INVALID);
	if (y < 0 || y >= data->height)
		return (INVALID);
	return (data->map[(x * data->width) + y]);
}

void	*sl_error(char *error_str)
{
	size_t	str_len;

	str_len = ft_strlen(error_str);
	write(2, "Error.\n", 7);
	write(2, error_str, str_len);
	return (0);
}
