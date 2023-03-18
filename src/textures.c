/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:50:48 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/17 21:00:26 by aruzafa-         ###   ########.fr       */
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

mlx_image_t	*sl_translate_texture(t_images *images, char type)
{
	if (type == '0')
		return (images->floor);
	if (type == '1')
		return (images->wall);
	if (type == 'C')
		return (images->collection);
	if (type == 'P')
		return (images->player);
	if (type == 'E')
		return (images->exit);
	return (0);
}
