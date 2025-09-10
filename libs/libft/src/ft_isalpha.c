/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:58:57 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/13 14:47:18 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	printf("%i", ft_isalpha('c'));
	printf("%i", ft_isalpha('D'));
	printf("%i", ft_isalpha('3'));
	printf("%i", ft_isalpha(' '));
}*/
