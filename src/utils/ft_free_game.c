/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:25:51 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/17 20:50:50 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_textures(t_game *game)
{
	if (game->img_wall.img)
		mlx_destroy_image(game->mlx, game->img_wall.img);
	if (game->img_space.img)
		mlx_destroy_image(game->mlx, game->img_space.img);
	if (game->img_exit.img)
		mlx_destroy_image(game->mlx, game->img_exit.img);
	if (game->img_collectible.img)
		mlx_destroy_image(game->mlx, game->img_collectible.img);
	if (game->img_player[0].img)
		mlx_destroy_image(game->mlx, game->img_player[0].img);
	if (game->img_player[1].img)
		mlx_destroy_image(game->mlx, game->img_player[1].img);
	if (game->img_player[2].img)
		mlx_destroy_image(game->mlx, game->img_player[2].img);
	if (game->img_player[3].img)
		mlx_destroy_image(game->mlx, game->img_player[3].img);
	if (game->img_player[4].img)
		mlx_destroy_image(game->mlx, game->img_player[4].img);
	if (game->img_player[5].img)
		mlx_destroy_image(game->mlx, game->img_player[5].img);
}

void	ft_free_game(t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			ft_free_array(game->map.grid);
		ft_free_textures(game);
		if (game->mlx && game->mlx_window)
			mlx_destroy_window(game->mlx, game->mlx_window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
}
