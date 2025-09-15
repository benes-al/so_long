/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:31:33 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/14 16:57:19 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_file_name(t_game *game)
{
	size_t	size;

	size = ft_strlen(game->map_file);
	if (size <= 4)
		ft_exit_error("Map file name is invalid.", game);
	if (!ft_strnstr(game->map_file + (size - 4), ".ber", 4))
		ft_exit_error("Map file extension is invalid.", game);
}
