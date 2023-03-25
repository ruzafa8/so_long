/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:10:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/25 17:50:13 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	sl_close_hook(void *param)
{
	if (!param)
		ft_printf("");
	ft_printf("About tu close");
}

void ft_hook(mlx_key_data_t keydata, void *param)
{
	t_data* game = param;
	(void) keydata;
	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	// ft_printf("keydata.action: %d\n", keydata.action); // Pulsar, soltar, repetir.
	// ft_printf("keydata.key: %d\n", keydata.key);
	// ft_printf("keydata.os_key: %d\n", keydata.os_key);
	// ft_printf("keydata.modifier: %d\n", keydata.modifier); //shift, control, ...
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	if (argc != 2)
		return ((int) sl_error("Número de argumentos inválido."));
	game = sl_read_map(argv[1]);
	if (!game)
		return (1);
	game->mlx = mlx_init(10 * TILE_SIZE, 10 * TILE_SIZE, "Hello42", true);
	if (!game->mlx)
		return ((int) sl_error("Hubo un error con al inicializar la MLX"));
	sl_load_images(game);
	sl_print_map(game);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_key_hook(game->mlx, ft_hook, (void *) game);
	mlx_close_hook(game->mlx, sl_close_hook, 0);
	mlx_loop(game->mlx);

	// @TODO: free images
	// @TODO: free data
	// @TODO: free mlx?
	return (0);
}
