/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:31:35 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/17 19:58:06 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	sl_read_map(mlx_t *mlx, t_images *images)
{
	char	*map_line;
	int		map_fd;
	mlx_image_t	*texture;
	int x;
	int y;

	ft_printf("Entrando en sl_read_map\n");
	map_fd = open("./assets/maps/map00.ber", O_RDONLY);
	map_line = ft_get_next_line(map_fd);
	y = 0;
	while (map_line)
	{
		x = 0;
		while (map_line[x] && map_line[x] != '\n')
		{
			ft_printf("%c ", map_line[x]);
			if (map_line[x] != '0')
				sl_print_texture(mlx, images->floor, x, y);
			texture = sl_translate_texture(images, map_line[x]);
			sl_print_texture(mlx, texture, x, y);
			x++;
		}
		ft_printf("\n");
		map_line = ft_get_next_line(map_fd);
		y++;
	}
}


*/