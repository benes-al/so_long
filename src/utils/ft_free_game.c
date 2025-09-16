/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:25:51 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/16 16:14:01 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	ft_free_textures(t_game *game)
{
	if (game->img_1.img)
		mlx_destroy_image(game->mlx, game->img_1.img);
	if (game->img_0.img)
		mlx_destroy_image(game->mlx, game->img_0.img);
	if (game->img_E.img)
		mlx_destroy_image(game->mlx, game->img_E.img);
	if (game->img_C.img)
		mlx_destroy_image(game->mlx, game->img_C.img);
	if (game->img_P[0].img)
		mlx_destroy_image(game->mlx, game->img_P[0].img);
	if (game->img_P[1].img)
		mlx_destroy_image(game->mlx, game->img_P[1].img);
	if (game->img_P[2].img)
		mlx_destroy_image(game->mlx, game->img_P[2].img);
	if (game->img_P[3].img)
		mlx_destroy_image(game->mlx, game->img_P[3].img);
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
