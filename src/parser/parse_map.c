/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:45:55 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/14 17:34:40 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *map_file, t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->map_file = map_file;
	is_valid_file_name(game);
	is_valid_map(game);
}