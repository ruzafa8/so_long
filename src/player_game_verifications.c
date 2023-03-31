/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_game_verifications.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:05:12 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/29 16:16:17 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_collect(t_data *game, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < game->num_col)
	{
		if (game->images->collection->instances[i].x == x * TILE_SIZE
			&& game->images->collection->instances[i].y == y * TILE_SIZE
			&& game->images->collection->instances[i].enabled)
		{
			game->images->collection->instances[i].enabled = 0;
		}
		i++;
	}
}

void	sl_verify_collect(t_data *game, int x, int y)
{
	if (sl_get_position(game, x, y) == COLLECTIONABLE)
	{
		delete_collect(game, x, y);
		sl_set_position(game, x, y, FLOOR);
		game->collected++;
	}
}

int	sl_verify_win(t_data *game, int x, int y)
{
	int	verification;

	verification = sl_get_position(game, x, y) == EXIT
		&& game->collected == game->num_col;
	game->win = verification;
	return (verification);
}
