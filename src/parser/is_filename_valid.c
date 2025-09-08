/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:31:33 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/08 14:39:51 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_file_name_valid(char *map_file)
{
	size_t size;
	
	size = ft_strlen(map_file);
	if (size <= 4)
		ft_exit_error("Map file name is invalid.");
	if (!ft_strnstr(map_file + (size - 4) , ".ber", 4))
		ft_exit_error("Map file extension is invalid.");
}
