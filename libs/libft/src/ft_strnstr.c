/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:40:52 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/26 10:13:31 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
	{
		return ((char *)big);
	}
	else if (!len)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if ((i + j < len) && (little[j + 1] == '\0'))
			{
				return (&((char *)big)[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/* 
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char *big = "42411013";
	char *little = "13";

	printf("%s\n", ft_strnstr(big, little, 9));
	printf("%s", strnstr(big, little, 9));
} */