/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:29:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 22:01:50 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_game *game)
{
	char	*line;

	line = file_in_one_line(game->map_file, game);
	if (game->map.grid)
		ft_free_array(game->map.grid);
	if (ft_strnstr(line, "\n\n", ft_strlen(line)))
		ft_exit_error("Map is not a rectangle.", game);
	game->map.grid = ft_split(line, '\n');
	free(line);
}
