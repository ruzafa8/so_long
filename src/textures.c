/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:50:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/19 19:00:53 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*sl_load_texture(mlx_t* mlx, char *path)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(path);
	img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	return (img);
}

void	sl_print_texture(mlx_t *mlx, mlx_image_t *texture, int x, int y)
{
	mlx_image_to_window(mlx, texture, x * TILE_SIZE, y * TILE_SIZE);
}

void	sl_print_map(mlx_t *mlx, t_data *data, t_images *images)
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
				sl_print_texture(mlx, sl_translate_texture(images, FLOOR), x, y);
			sl_print_texture(mlx, sl_translate_texture(images, value), x, y);
			x++;
		}
		y++;
	}
}

mlx_image_t	*sl_translate_texture(t_images *images, t_value type)
{
	if (type == FLOOR)
		return (images->floor);
	if (type == WALL)
		return (images->wall);
	if (type == COLLECTIONABLE)
		return (images->collection);
	if (type == PLAYER)
		return (images->player);
	if (type == EXIT)
		return (images->exit);
	return (0);
}
