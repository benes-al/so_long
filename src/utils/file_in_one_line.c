/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_in_one_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:14:18 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/13 03:16:29 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*file_in_one_line(char *map_file, t_game *game)
{
	char	*file_in_one_line;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_exit_error("Couldn't open requeste map file.", game);
	line = get_next_line(fd);
	if (ft_strclen(line, '\n') == 0)
	{
		free(line);
		ft_exit_error("Map in empty.", game);
	}
	tmp = ft_strdup("");
	while (line)
	{
		file_in_one_line = ft_strjoin(tmp, line);
		free(tmp);
		tmp = file_in_one_line;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file_in_one_line);
}
