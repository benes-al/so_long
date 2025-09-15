/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_valid_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:36:37 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/13 11:57:23 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	characters_count(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.grid[j])
	{
		i = 0;
		while (game->map.grid[j][i])
		{
			if (game->map.grid[j][i] == PLAYER)
			{
				game->player.current_pos = (t_player_pos){j, i};
				game->player.next_pos = (t_player_pos){j, i};
				game->player_count++;
			}
			else if (game->map.grid[j][i] == EXIT)
				game->exit_count++;
			else if (game->map.grid[j][i] == COLLECTIBLE)
				game->collectible_count++;
			else if (!ft_strchr(TILES, game->map.grid[j][i]))
				ft_exit_error("Map has invalid tiles", game);
			i++;
		}
		j++;
	}
}

static void	is_valid_characters_count(t_game *game)
{
	if (game->player_count != 1)
		ft_exit_error("Invalid number of players on the map", game);
	if (game->collectible_count < 1)
		ft_exit_error("Invalid number of collectibles on the map.", game);
	if (game->exit_count != 1)
		ft_exit_error("Invalid number of exits on the map", game);
}

void	are_valid_characters(t_game *game)
{
	characters_count(game);
	is_valid_characters_count(game);
}
