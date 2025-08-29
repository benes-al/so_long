/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:00:26 by benes-al          #+#    #+#             */
/*   Updated: 2025/08/25 18:51:07 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void *mlx;
	void *win;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "so_long text");
	(void)win;
	mlx_loop(mlx);
	return(0);
}
