/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:50:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 18:44:13 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*sl_load_texture(mlx_t *mlx, char *path)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(path);
	img = mlx_texture_to_image(mlx, tex);
	mlx_delete_texture(tex);
	return (img);
}

void	sl_print_texture(t_data *data, t_value value, int x, int y)
{
	mlx_image_t	*texture;

	texture = sl_translate_texture(data, value);
	mlx_image_to_window(data->mlx, texture, x * TILE_SIZE, y * TILE_SIZE);
}

void	sl_print_position(t_data *data, int x, int y)
{
	mlx_image_t	*texture;

	texture = sl_translate_position(data, x, y);
	mlx_image_to_window(data->mlx, texture, x * TILE_SIZE, y * TILE_SIZE);
}

mlx_image_t	*sl_translate_position(t_data *data, int x, int y)
{
	t_value	type;
	int		wall_type;

	type = sl_get_position(data, x, y);
	if (type == FLOOR)
		return (data->images->floor);
	if (type == WALL)
	{
		wall_type = (sl_get_position(data, x, y - 1) == WALL) * 8;
		wall_type += (sl_get_position(data, x, y + 1) == WALL) * 2;
		wall_type += (sl_get_position(data, x - 1, y) == WALL) * 1;
		wall_type += (sl_get_position(data, x + 1, y) == WALL) * 4;
		return (data->images->wall[wall_type]);
	}
	if (type == COLLECTIONABLE)
		return (data->images->collection);
	if (type == PLAYER)
		return (data->images->player);
	if (type == EXIT)
		return (data->images->exit);
	return (0);
}

mlx_image_t	*sl_translate_texture(t_data *data, t_value type)
{
	if (type == FLOOR)
		return (data->images->floor);
	if (type == WALL)
		return (data->images->wall[0]);
	if (type == COLLECTIONABLE)
		return (data->images->collection);
	if (type == PLAYER)
		return (data->images->player);
	if (type == EXIT)
		return (data->images->exit);
	return (0);
}
