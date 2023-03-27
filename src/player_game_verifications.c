/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_game_verifications.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:05:12 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/27 20:18:57 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_verify_collect(t_data *game, int x, int y)
{
	if (sl_get_position(game, x, y) == COLLECTIONABLE)
	{
		game->collected++;
		sl_set_position(game, x, y, FLOOR);
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
