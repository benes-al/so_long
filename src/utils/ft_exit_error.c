/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:26:36 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/08 14:41:05 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_error(char *error_message)
{	
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}