/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:22:52 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/31 19:10:24 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_images(mlx_t *mlx, t_images *images)
{
	size_t	i;

	i = 0;
	mlx_delete_image(mlx, images->collection);
	mlx_delete_image(mlx, images->exit);
	mlx_delete_image(mlx, images->floor);
	while (i < 16)
	{
		mlx_delete_image(mlx, images->player[i]);
		mlx_delete_image(mlx, images->wall[i]);
		i++;
	}
	free(images->player);
	free(images->wall);
}

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
		if ((*data)->images)
			free_images((*data)->mlx, (*data)->images);
		free(*data);
		mlx_terminate((*data)->mlx);
	}
}

t_value	sl_get_position(t_data *data, size_t x, size_t y)
{
	if (x < 0 || x >= data->width)
		return (INVALID);
	if (y < 0 || y >= data->height)
		return (INVALID);
	return (data->map[(y * data->width) + x]);
}

void	sl_set_position(t_data *data, size_t x, size_t y, t_value value)
{
	if (x < 0 || x >= data->width)
		return ;
	if (y < 0 || y >= data->height)
		return ;
	data->map[(y * data->width) + x] = value;
}

void	*sl_error(char *error_str)
{
	size_t	str_len;

	str_len = ft_strlen(error_str);
	write(2, "Error.\n", 7);
	write(2, error_str, str_len);
	return (0);
}
