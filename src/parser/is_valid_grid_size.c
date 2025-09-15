/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_grid_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:52:38 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/13 11:57:46 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_grid_size(t_game *game)
{
	int	j;

	j = 0;
	game->map.cols = ft_strlen(game->map.grid[j]);
	while (game->map.grid[j])
	{
		if (ft_strlen(game->map.grid[j]) != game->map.cols)
			ft_exit_error("Map is not a rectangle.", game);
		j++;
	}
	game->map.rows = j;
}
