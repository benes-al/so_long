/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:15:48 by benes-al          #+#    #+#             */
/*   Updated: 2025/09/08 18:17:21 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			occ = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (occ);
}
/*
int	main(void)
{
	char s[10] = "casacx";

	printf("%s", ft_strrchr(s, 'c'));
}*/