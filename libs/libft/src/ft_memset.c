/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:57:07 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/16 19:41:23 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) s;
	while (i < n)
	{
		p[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	test[5];
	int		i;

	i = 0;
//	ft_memset(test, '*', 5);
//	ft_memset(test, '-', 0);
	ft_memset(test, 'Z', 1);
	while (test[i])
	{
		printf("%c", test[i]);
		i++;
	}
	printf("\n");
}*/
