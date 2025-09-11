/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_enclosed_by_walls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:15:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 22:19:20 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_enclosed_by_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.grid[i])
	{
		if (game->map.grid[i][0] != WALL)
			ft_exit_error("Map is not surrounded by walls.", game);
		if (game->map.grid[i][game->map.cols - 1] != WALL)
			ft_exit_error("Map is not surrounded by walls.", game);
		i++;
	}
	i = 0;
	while (game->map.grid[0][i] && game->map.grid[game->map.rows - 1][i])
	{
		if (game->map.grid[0][i] != WALL)
			ft_exit_error("Map is not surrounded by walls.", game);
		if (game->map.grid[game->map.rows - 1][i] != WALL)
			ft_exit_error("Map is not surrounded by walls.", game);
		i++;
	}
}
