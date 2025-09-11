/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:29:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 21:58:48 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(char *map_file, t_game *game)
{
	char	*line;

	line = file_in_one_line(map_file, game);
	if (game->map.grid)
		ft_free_array(game->map.grid);
	game->map.grid = ft_split(line, '\n');
	free(line);
}
