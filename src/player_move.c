/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:29:28 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/31 16:24:20 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_position(size_t *x, size_t *y, t_direction direction)
{
	if (direction == UP)
		*y = *y - 1;
	if (direction == DOWN)
		*y = *y + 1;
	if (direction == LEFT)
		*x = *x - 1;
	if (direction == RIGHT)
		*x = *x + 1;
}

static int	valid_position(t_data *game, size_t x, size_t y)
{
	t_value	position;

	position = sl_get_position(game, x, y);
	if (position == WALL || position == EXIT)
		return (0);
	return (1);
}

static void	change_player_position(t_data *game, size_t x, size_t y, t_direction direction)
{
	size_t	i;

	game->player->x = x;
	game->player->y = y;
	i = 0;
	while (i < 16)
		game->images->player[i++]->instances[0].enabled = 0;
	if (direction == UP)
		i = 4;
	if (direction == LEFT)
		i = 12;
	if (direction == DOWN)
		i = 0;
	if (direction == RIGHT)
		i = 8;
	game->images->player[i]->instances[0].x = TILE_SIZE * x;
	game->images->player[i]->instances[0].y = TILE_SIZE * y;
	game->images->player[i]->instances[0].enabled = 1;
}

void	sl_player_move(t_data *game, t_direction direction)
{
	size_t	x;
	size_t	y;
	t_value	new_position;

	x = game->player->x;
	y = game->player->y;
	update_position(&x, &y, direction);
	new_position = sl_get_position(game, x, y);
	if (valid_position(game, x, y))
	{
		game->num_movs++;
		ft_printf("%d\n", game->num_movs);
		change_player_position(game, x, y, direction);
	}
	sl_verify_collect(game, x, y);
	if (new_position == EXIT)
	{
		if (sl_verify_win(game, x, y))
			ft_printf("Has ganado.\n");
		else
			ft_printf("No se han recolectado todos los coleccionables\n");
	}
}
