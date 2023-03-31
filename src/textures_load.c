/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:31:35 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/31 16:10:24 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	**load_wall(t_data *game)
{
	mlx_image_t	**walls;

	walls = (mlx_image_t **) ft_calloc(16, sizeof(mlx_image_t *));
	if (!walls)
		return (0);
	walls[0] = sl_load_texture(game->mlx, "./assets/textures/fence_0.png");
	walls[1] = sl_load_texture(game->mlx, "./assets/textures/fence_1.png");
	walls[2] = sl_load_texture(game->mlx, "./assets/textures/fence_2.png");
	walls[3] = sl_load_texture(game->mlx, "./assets/textures/fence_3.png");
	walls[4] = sl_load_texture(game->mlx, "./assets/textures/fence_4.png");
	walls[5] = sl_load_texture(game->mlx, "./assets/textures/fence_5.png");
	walls[6] = sl_load_texture(game->mlx, "./assets/textures/fence_6.png");
	walls[7] = sl_load_texture(game->mlx, "./assets/textures/fence_7.png");
	walls[8] = sl_load_texture(game->mlx, "./assets/textures/fence_8.png");
	walls[9] = sl_load_texture(game->mlx, "./assets/textures/fence_9.png");
	walls[10] = sl_load_texture(game->mlx, "./assets/textures/fence_10.png");
	walls[11] = sl_load_texture(game->mlx, "./assets/textures/fence_11.png");
	walls[12] = sl_load_texture(game->mlx, "./assets/textures/fence_12.png");
	walls[13] = sl_load_texture(game->mlx, "./assets/textures/fence_13.png");
	walls[14] = sl_load_texture(game->mlx, "./assets/textures/fence_14.png");
	walls[15] = sl_load_texture(game->mlx, "./assets/textures/fence_15.png");
	return (walls);
}

static mlx_image_t	**load_chicken(t_data *game)
{
	mlx_image_t	**chicken;

	chicken = (mlx_image_t **) ft_calloc(16, sizeof(mlx_image_t *));
	if (!chicken)
		return (0);
	chicken[0] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_0_0.png");
	chicken[1] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_0_1.png");
	chicken[2] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_0_2.png");
	chicken[3] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_0_3.png");
	chicken[4] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_2_0.png");
	chicken[5] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_2_1.png");
	chicken[6] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_2_2.png");
	chicken[7] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_2_3.png");
	chicken[8] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_1_0.png");
	chicken[9] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_1_1.png");
	chicken[10] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_1_2.png");
	chicken[11] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_1_3.png");
	chicken[12] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_3_0.png");
	chicken[13] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_3_1.png");
	chicken[14] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_3_2.png");
	chicken[15] = sl_load_texture(game->mlx, "./assets/textures/chicken_walk_3_3.png");
	return (chicken);
}

void	sl_load_images(t_data *game)
{
	game->images = (t_images *) ft_calloc(1, sizeof(t_images));
	if (!game->images)
		return ;
	game->images->player = load_chicken(game);
	game->images->floor = sl_load_texture(game->mlx,
			"./assets/textures/CHAN_64.png");
	game->images->wall = load_wall(game);
	game->images->exit = sl_load_texture(game->mlx,
			"./assets/textures/ESCALERA.png");
	game->images->collection = sl_load_texture(game->mlx,
			"./assets/textures/COFRE.png");
}
