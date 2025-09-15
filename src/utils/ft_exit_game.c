/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:17:15 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/15 16:22:29 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_game(char *message, t_game *game)
{
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	ft_free_game(game);
	exit(EXIT_SUCCESS);
}
