/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:52:38 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/08 18:35:10 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_valid(char *map_file, t_game *game)
{
	char	*line;

	game->map.fd = open(map_file, O_RDONLY);
	if (game->map.fd == -1)
		ft_exit_error("Couldn't open requeste map file");
	line = get_next_line(game->map.fd);
	game->map.cols = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != (size_t)game->map.cols)
			ft_exit_error("Map is not a rectangle");
		ft_printf("%i\n", ft_strlen(line));
		ft_printf("%i\n", ft_strclen(line, '\n'));
		line = get_next_line(game->map.fd);
	}
}	