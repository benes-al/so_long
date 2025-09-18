/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:46:13 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 20:24:02 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	next_position(t_game *game, int x, int y)
{
	game->player.next_pos = (t_player_pos){y, x};
	render_move(game, game->player.current_tile, PLAYER, &game->player);
	game->map.grid[game->player.current_pos.y][game->player.current_pos.x]
		= game->player.current_tile;
	game->player.current_pos = game->player.next_pos;
	game->player.current_tile = game->map.grid[y][x];
	game->map.grid[y][x] = PLAYER;
}

void	check_move(t_game *game, int x, int y)
{
	game->false_count_moves++;
	if (game->map.grid[y][x] == WALL && game->player.current_tile == EXIT)
	{
		game->player.img_index = FALSE_EXIT_FACE;
		put_player_tile(game);
		return ;
	}
	if (game->map.grid[y][x] == WALL)
		return ;
	print_moves(game);
	if (game->map.grid[y][x] == COLLECTIBLE)
	{
		game->map.grid[y][x] = SPACE;
		game->collectible_count--;
	}
	else if (game->map.grid[y][x] == EXIT && !game->collectible_count)
		ft_exit_game("Congrats! You’ve got a climbing buddy now! 🧗", game);
	else if (game->map.grid[y][x] == EXIT)
	{
		game->player.img_index = FALSE_EXIT_FACE;
		put_player_tile(game);
		ft_printf("You are not T'alex R'honnold\n");
	}
	next_position(game, x, y);
}
