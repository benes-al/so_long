/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_game_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:03:47 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/18 15:49:04 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, char tile, t_player_pos point, int img_index)
{
	if (tile == SPACE || tile == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_space.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == EXIT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_exit.img, point.x * TILE_SIZE, point.y * TILE_SIZE);
	else if (tile == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_collectible.img, point.x * TILE_SIZE,
			point.y * TILE_SIZE);
	else if (tile == PLAYER)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->img_player[img_index].img,
			point.x * TILE_SIZE, point.y * TILE_SIZE);
}
