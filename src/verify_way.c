/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:10:40 by aruzafa-          #+#    #+#             */
/*   Updated: 2023/03/31 17:55:20 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visit_position(t_data *game, size_t x, size_t y)
{
	t_value	pos;

	if (x < 0 || x > game->width || y < 0 || y > game->height)
		return ;
	pos = sl_get_position(game, x, y);
	if (pos == WALL)
		return ;
	if (pos == COLLECTIONABLE)
		game->collected++;
	if (pos == EXIT)
	{
		game->win = 1;
		return ;
	}
	sl_set_position(game, x, y, WALL);
	visit_position(game, x + 1, y);
	visit_position(game, x - 1, y);
	visit_position(game, x, y + 1);
	visit_position(game, x, y - 1);
}

int	sl_verify_way(t_data *game, char *map)
{
	t_data	aux;

	aux.width = game->width;
	aux.height = game->height;
	aux.map = sl_ctov(map, aux.width, aux.height);
	aux.collected = 0;
	aux.win = 0;
	visit_position(&aux, game->player->x, game->player->y);
	return (aux.collected == game->num_col && aux.win == 1);
}
