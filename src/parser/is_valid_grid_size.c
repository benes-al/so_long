/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_grid_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:52:38 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 19:45:10 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_grid_size(char *map_file, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_exit_error("Couldn't open requeste map file.", game);
	line = get_next_line(fd);
	game->map.cols = ft_strclen(line, '\n');
	if (game->map.cols == 0)
	{
		free(line);
		ft_exit_error("Map in empty.", game);
	}
	while (line)
	{
		if (ft_strclen(line, '\n') != game->map.cols)
		{
			free (line);
			ft_exit_error("Map is not a rectangle.", game);
		}
		game->map.rows++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}
