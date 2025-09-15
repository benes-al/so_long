/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_esc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:39:10 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/15 16:22:15 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_esc(t_game *game)
{
	ft_putstr_fd("Why are you quitting? Come on, you're a great climber!", 1);
	ft_putstr_fd("\n", 1);
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}
