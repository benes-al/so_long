/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:24:23 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/13 01:18:24 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_path(t_game *game, t_player_pos current_pos)
{
	static int	collectible;
	static int	exit;
	char		tile;		

	tile = game->map.grid[current_pos.y][current_pos.x];
	if (tile == WALL || tile == VISITED)
		return ;
	if (tile == EXIT)
		exit++;
	else if (tile == COLLECTIBLE)
		collectible++;
	game->map.grid[current_pos.y][current_pos.x] = VISITED;
	is_valid_path(game, (t_player_pos){current_pos.y + 1, current_pos.x});
	is_valid_path(game, (t_player_pos){current_pos.y - 1, current_pos.x});
	is_valid_path(game, (t_player_pos){current_pos.y, current_pos.x + 1});
	is_valid_path(game, (t_player_pos){current_pos.y, current_pos.x - 1});
	if (current_pos.y == game->player.current_pos.y
		&& current_pos.x == game->player.current_pos.x)
		if (collectible != game->collectible_count || exit != game->exit_count)
			ft_exit_error("Map has invalid path.", game);
}
