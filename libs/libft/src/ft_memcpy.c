/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:24:52 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/15 14:38:36 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ft_dest;
	const unsigned char	*ft_src;
	size_t				i;

	ft_dest = (unsigned char *) dest;
	ft_src = (const unsigned char *) src;
	i = 0;
	if (n == 0)
	{
		return (dest);
	}
	if (!ft_dest && !ft_src)
	{
		return (NULL);
	}
	while (i < n)
	{
		ft_dest[i] = ft_src[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "casa";
	char dest[] = "-";
	printf("src: %s, dest: %s\n", src, dest);
	printf("ft_dest: %s\n", (char *)ft_memcpy(dest, src, 2));
	printf("ft_dest: %s\n", (char *)ft_memcpy(dest, src, 2));
}*/
