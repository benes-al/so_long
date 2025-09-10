/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_grid_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:52:38 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/10 22:18:30 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_grid_size(char *map_file, t_game *game)
{
	char	*line;

	game->map.fd = open(map_file, O_RDONLY);
	if (game->map.fd == -1)
		ft_exit_error("Couldn't open requeste map file.");
	line = get_next_line(game->map.fd);
	game->map.cols = ft_strclen(line, '\n');
	if (game->map.cols == 0)
	{
		free(line);
		ft_exit_error("Map in empty.");
	}
	while (line)
	{
		if (ft_strclen(line, '\n') != game->map.cols)
		{
			free (line); 
			ft_exit_error("Map is not a rectangle.");
		}
		game->map.rows++;
		free(line);
		line = get_next_line(game->map.fd);
	}
	close (game->map.fd);
}
