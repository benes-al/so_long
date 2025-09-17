/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:43:21 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 20:37:29 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile_and_check_move(int keycode, t_game *game)
{
	put_player_tile(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		check_move(game, game->player.current_pos.x,
			game->player.current_pos.y - 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		check_move(game, game->player.current_pos.x - 1,
			game->player.current_pos.y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		check_move(game, game->player.current_pos.x,
			game->player.current_pos.y + 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		check_move(game, game->player.current_pos.x + 1,
			game->player.current_pos.y);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player.img_index = PULLED_BY_ROPE;
		put_tile_and_check_move(keycode, game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player.img_index = RUN_LEFT + !(game->false_count_moves % 2);
		put_tile_and_check_move(keycode, game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player.img_index = PULLED_BY_ROPE;
		put_tile_and_check_move(keycode, game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player.img_index = RUN_RIGHT + !(game->false_count_moves % 2);
		put_tile_and_check_move(keycode, game);
	}
	else if (keycode == KEY_ESC)
		ft_exit_game("Keep climbing, rockstar! You're a great climber!", game);
	return (0);
}
