/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:01:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 22:04:56 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *g)
{
	create_map(g);
	g->mlx = mlx_init();
	if (!g->mlx)
		ft_exit_error("Couldn't initialize mlx.", g);
	load_textures(g);
	g->mlx_window = mlx_new_window(g->mlx, g->map.cols * TILE_SIZE,
			g->map.rows * TILE_SIZE, "so_long");
	if (!g->mlx_window)
		ft_exit_error("Couldn't create window", g);
	render_map(g, -1, -1);
}
