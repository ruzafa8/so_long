/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:10:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/31 19:16:17 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	sl_close_hook(void *param)
{
	(void) param;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	if (!game->win
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			sl_player_move(game, LEFT);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			sl_player_move(game, DOWN);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			sl_player_move(game, RIGHT);
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			sl_player_move(game, UP);
	}
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
		return ((int) sl_error("Número de argumentos inválido."));
	game = sl_read_map(argv[1]);
	if (!game)
		return (1);
	game->mlx = mlx_init(
			game->width * TILE_SIZE,
			game->height * TILE_SIZE, "ChickenPollos42", true);
	if (!game->mlx)
		return ((int) sl_error("Hubo un error con al inicializar la MLX"));
	sl_load_images(game);
	if (!game->images)
		return (1);
	sl_print_map(game);
	mlx_key_hook(game->mlx, &ft_hook, game);
	mlx_close_hook(game->mlx, &sl_close_hook, 0);
	mlx_loop(game->mlx);
	// @TODO: free images
	// @TODO: free data
	// @TODO: free mlx?
	sl_free_data(&game);
	return (0);
}
