/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:01:31 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 09:41:16 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map(t_game *game, int i, int j)
{
	t_img	*tile;

	tile = &game->img_1;
	while (++i < (int)game->map.rows)
	{
		j = -1;
		while (++j < (int)game->map.cols)
		{
			if (game->map.grid[i][j] == WALL)
				tile = &game->img_1;
			else if (game->map.grid[i][j] == SPACE)
				tile = &game->img_0;
			else if (game->map.grid[i][j] == EXIT)
				tile = &game->img_E;
			else if (game->map.grid[i][j] == COLLECTIBLE)
				tile = &game->img_C;
			else if (game->map.grid[i][j] == PLAYER)
				tile = &game->img_P[1];
			mlx_put_image_to_window(game->mlx, game->mlx_window, tile->img,
				j * TILE_SIZE, i * TILE_SIZE);
		}
	}
}

static void load_textures(t_game *g)
{
	g->img_1.img = mlx_xpm_file_to_image(g->mlx, W_XPM, &g->x, &g->y);
	g->img_0.img = mlx_xpm_file_to_image(g->mlx, S_XPM, &g->x, &g->y);
	g->img_E.img = mlx_xpm_file_to_image(g->mlx, E_XPM, &g->x, &g->y);
	g->img_C.img = mlx_xpm_file_to_image(g->mlx, C_XPM, &g->x, &g->y);
	g->img_P[0].img = mlx_xpm_file_to_image(g->mlx, P1_XPM, &g->x, &g->y);
	g->img_P[1].img = mlx_xpm_file_to_image(g->mlx, P2_XPM, &g->x, &g->y);
	g->img_P[2].img = mlx_xpm_file_to_image(g->mlx, P3_XPM, &g->x, &g->y);
	g->img_P[3].img = mlx_xpm_file_to_image(g->mlx, P4_XPM, &g->x, &g->y);
	g->img_P[4].img = mlx_xpm_file_to_image(g->mlx, P5_XPM, &g->x, &g->y);
	g->img_P[5].img = mlx_xpm_file_to_image(g->mlx, P6_XPM, &g->x, &g->y);
	if (!g->img_1.img || !g->img_0.img || !g->img_E.img
		|| !g->img_C.img || !g->img_P[0].img
		|| !g->img_P[1].img || !g->img_P[2].img
		|| !g->img_P[3].img || !g->img_P[4].img || !g->img_P[4].img)
		ft_exit_error("Couldn't load textures.", g);
}

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
