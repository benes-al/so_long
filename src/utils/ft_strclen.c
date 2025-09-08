/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:37:34 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/08 18:37:36 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t ft_strclen(const char *str, const char c)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != c)
		len++;
	return (len);
}
