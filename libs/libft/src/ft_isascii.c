/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:19:39 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/24 18:19:43 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%i", ft_isascii('c'));
	printf("%i", ft_isascii('!'));
	printf("%i", ft_isascii('3'));
	printf("%i", ft_isascii('0x80'));
}*/
