/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:10:23 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/18 14:10:56 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return ((int) sl_print_error("Error\nNúmero de argumentos inválido."));
	mlx_t* mlx = mlx_init(10 * TILE_SIZE, 10 * TILE_SIZE, "Hello42", true);
	if (!mlx)
		return ((int) sl_print_error("Error\nHubo un error con al inicializar la MLX"));

	t_images images;
	t_data *data = sl_read_map(argv[1]);
	if (!data)
		return (1);

	images.player = sl_load_texture(mlx, "./assets/textures/CHICKEN.png");
	images.floor = sl_load_texture(mlx, "./assets/textures/CHAN.png");
	images.wall = sl_load_texture(mlx, "./assets/textures/SETO.png");
	images.exit = sl_load_texture(mlx, "./assets/textures/ESCALERA.png");
	images.collection = sl_load_texture(mlx, "./assets/textures/COFRE.png");


	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return (1);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
