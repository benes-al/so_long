/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:27:20 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/15 16:53:48 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_game *game, char tile, t_player_pos point, int img_index)
{		
	if (tile == SPACE || tile == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_0.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_E.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_C.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_P[img_index].img,
			point.x * TILE_SIZE, point.y * TILE_SIZE);
}

void	render_move(t_game *game, char current, char next, t_player *player)
{
	put_tile(game, current, player->current_pos, player->img_index);
	put_tile(game, next, player->next_pos, player->img_index);
}
