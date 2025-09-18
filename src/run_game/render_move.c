/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:27:20 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 20:34:37 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_move(t_game *game, char current, char next, t_player *player)
{
	put_tile(game, current, player->current_pos, player->img_index);
	put_tile(game, next, player->next_pos, player->img_index);
}
