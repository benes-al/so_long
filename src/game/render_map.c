/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:10:06 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 21:56:44 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game, int i, int j)
{
	t_img	*tile;

	tile = &game->img_wall;
	while (++i < (int)game->map.rows)
	{
		j = -1;
		while (++j < (int)game->map.cols)
		{
			if (game->map.grid[i][j] == WALL)
				tile = &game->img_wall;
			else if (game->map.grid[i][j] == SPACE)
				tile = &game->img_space;
			else if (game->map.grid[i][j] == EXIT)
				tile = &game->img_exit;
			else if (game->map.grid[i][j] == COLLECTIBLE)
				tile = &game->img_collectible;
			else if (game->map.grid[i][j] == PLAYER)
				tile = &game->img_player[1];
			mlx_put_image_to_window(game->mlx, game->mlx_window, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}
