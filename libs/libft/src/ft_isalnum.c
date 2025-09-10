/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:32:52 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/13 14:48:10 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isalnum('c'));
	printf("%i", ft_isalnum('D'));
	printf("%i", ft_isalnum('3'));
	printf("%i", ft_isalnum(' '));
}*/
