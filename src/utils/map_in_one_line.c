/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in_one_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:50:06 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/10 19:52:06 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_in_one_line(char *map_file, t_game *game)
{
	char	*map_in_one_line;
	char	*line;
	char	*tmp;

	game->map.fd = open(map_file, O_RDONLY);
	if (game->map.fd == -1)
		ft_exit_error("Couldn't open requeste map file.");
	line = get_next_line(game->map.fd);
	tmp = ft_strdup("");
	while (line)
	{
		map_in_one_line = ft_strjoin(tmp, line);
		free(tmp);
		tmp = map_in_one_line;
		free(line);
		line = get_next_line(game->map.fd);
	}
	close(game->map.fd);
}
