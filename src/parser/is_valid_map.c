/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:01:47 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 22:26:15 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_map(char *map_file, t_game *game)
{
	is_valid_grid_size(map_file, game);
	create_map(map_file, game);
	is_map_enclosed_by_walls(game);
	are_valid_characters(game);
	//is_valid_path(game);
}
