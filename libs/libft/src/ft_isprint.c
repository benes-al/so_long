/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 06:54:24 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/14 07:01:15 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	printf("%i", ft_isprint('A'));
	printf("%i", ft_isprint('9'));
	printf("%i", ft_isprint(' '));
	printf("%i", ft_isprint('~'));
	printf("%i", ft_isprint('\n'));
	printf("%i", ft_isprint('\t'));
	printf("%i", ft_isprint('\0'));
}*/
