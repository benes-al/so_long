/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:58:57 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/13 14:47:29 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	printf("%i", ft_isdigit('c'));
	printf("%i", ft_isdigit('D'));
	printf("%i", ft_isdigit('3'));
	printf("%i", ft_isdigit(' '));
}*/
