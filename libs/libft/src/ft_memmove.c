/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:02:28 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/15 16:14:40 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ft_dest;
	const unsigned char	*ft_src;
	size_t				i;

	if (n == 0)
		return (dest);
	if (!src && !dest)
		return (NULL);
	ft_dest = (unsigned char *)dest;
	ft_src = (const unsigned char *)src;
	i = 0;
	if (ft_dest < ft_src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > i)
		{
			ft_dest[n - 1] = ft_src[n - 1];
			n--;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "abc";
	char	dest[] = "1234567";
	printf("src: %s, dest: %s\n", src, dest);
	printf("ft_dest: %s\n", (char *)ft_memmove(dest, src, 3));
	printf("ft_dest: %s\n", (char *)ft_memmove(dest, src, 2));
}*/