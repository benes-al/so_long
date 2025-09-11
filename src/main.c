/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:00:26 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/11 22:08:31 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_exit_error("Usage: ./so_long <map.name>.ber", &game);
	is_valid_file_name(argv[1], &game);
	ft_bzero(&game, sizeof(game));
	is_valid_map(argv[1], &game);
	
	ft_free_array(game.map.grid);
}
