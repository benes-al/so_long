/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player_tile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:08:34 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 21:50:25 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_tile(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->img_player[game->player.img_index].img,
		game->player.current_pos.x * TILE_SIZE,
		game->player.current_pos.y * TILE_SIZE);
}
