/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:06:35 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 21:47:58 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *g)
{
	g->img_wall.img = mlx_xpm_file_to_image(g->mlx, W_XPM, &g->x, &g->y);
	g->img_space.img = mlx_xpm_file_to_image(g->mlx, S_XPM, &g->x, &g->y);
	g->img_exit.img = mlx_xpm_file_to_image(g->mlx, E_XPM, &g->x, &g->y);
	g->img_collectible.img = mlx_xpm_file_to_image(g->mlx, C_XPM, &g->x, &g->y);
	g->img_player[0].img = mlx_xpm_file_to_image(g->mlx, P1_XPM, &g->x, &g->y);
	g->img_player[1].img = mlx_xpm_file_to_image(g->mlx, P2_XPM, &g->x, &g->y);
	g->img_player[2].img = mlx_xpm_file_to_image(g->mlx, P3_XPM, &g->x, &g->y);
	g->img_player[3].img = mlx_xpm_file_to_image(g->mlx, P4_XPM, &g->x, &g->y);
	g->img_player[4].img = mlx_xpm_file_to_image(g->mlx, P5_XPM, &g->x, &g->y);
	g->img_player[5].img = mlx_xpm_file_to_image(g->mlx, P6_XPM, &g->x, &g->y);
	if (!g->img_wall.img || !g->img_space.img || !g->img_exit.img
		|| !g->img_collectible.img || !g->img_player[0].img
		|| !g->img_player[1].img || !g->img_player[2].img
		|| !g->img_player[3].img || !g->img_player[4].img
		|| !g->img_player[5].img)
		ft_exit_error("Couldn't load textures.", g);
}
