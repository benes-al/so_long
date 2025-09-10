/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:56:06 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/15 10:33:34 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) s;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	test[10];
	int		i;

	i = 0;
	ft_bzero(test, 10);
	while (test[i])
	{
		printf("%c", test[i]);
		i++;
	}
	printf("\n");
}*/
