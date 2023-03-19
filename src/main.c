/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:10:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/19 20:00:17 by aruzafa-         ###   ########.fr       */
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
	(void) game;
	(void) keydata;
	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	// ft_printf("keydata.action: %d\n", keydata.action); // Pulsar, soltar, repetir.
	// ft_printf("keydata.key: %d\n", keydata.key);
	// ft_printf("keydata.os_key: %d\n", keydata.os_key);
	// ft_printf("keydata.modifier: %d\n", keydata.modifier); //shift, control, ...
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_printf("Habemo pursao la tecla esqueip");
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return ((int) sl_print_error("Error\nNúmero de argumentos inválido."));
	mlx_t* mlx = mlx_init(10 * TILE_SIZE, 10 * TILE_SIZE, "Hello42", true);
	if (!mlx)
		return ((int) sl_print_error("Error\nHubo un error con al inicializar la MLX"));

	t_data *game = sl_read_map(argv[1]);
	if (!game)
		return (1);

	game->images = (t_images *) ft_calloc(1, sizeof(t_images));
	ft_printf("%p", game->images);
	if (!game->images) //@TODO: Free game.
		return (0);
	game->images->player = sl_load_texture(mlx, "./assets/textures/CHICKEN.png");
	// game->images->floor = sl_load_texture(mlx, "./assets/textures/CHAN.png");
	// game->images->wall = sl_load_texture(mlx, "./assets/textures/SETO.png");
	// game->images->exit = sl_load_texture(mlx, "./assets/textures/ESCALERA.png");
	// game->images->collection = sl_load_texture(mlx, "./assets/textures/COFRE.png");

	//sl_print_map(mlx, game);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_key_hook(mlx, ft_hook, (void *) game);
	//mlx_close_hook(mlx, sl_close_hook, 0);
	//mlx_loop(mlx);
	//mlx_terminate(mlx);
	// @TODO: free images
	// @TODO: free data
	// @TODO: free mlx?
	return (0);
}
