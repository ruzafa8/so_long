/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:29:28 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/27 19:36:26 by aruzafa-         ###   ########.fr       */
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
	t_value position;

	position = sl_get_position(game, x, y);
	if (position == WALL)
		return (0);
	return (1);
}

static void	change_player_position(t_data *game, size_t x, size_t y)
{
	sl_print_texture(game, FLOOR, game->player->x, game->player->y);
	game->player->x = x;
	game->player->y = y;
	sl_print_texture(game, FLOOR, x, y);
	sl_print_texture(game, PLAYER, x, y);
}

void	sl_player_move(t_data *game, t_direction direction)
{
	size_t	x;
	size_t	y;

	x = game->player->x;
	y = game->player->y;
	update_position(&x, &y, direction);
	if (valid_position(game, x, y))
	{
		game->num_movs++;
		ft_printf("%d\n", game->num_movs);
		change_player_position(game, x, y);
	}
}
