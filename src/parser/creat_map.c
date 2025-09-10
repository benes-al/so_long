/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:29:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/10 22:34:09 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creat_map(char *map_file, t_game *game)
{
	char	*line;
	char	**map;
	
	line = map_in_one_line(map_file, game);
	map = ft_split(line, '\n');
	
}