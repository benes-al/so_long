/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:51:41 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/25 16:38:13 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ismatch(char const c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_ismatch(s1[start], set) == 1)
	{
		start++;
	}
	while (end > start && ft_ismatch(s1[end], set) == 1)
	{
		end--;
	}
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}

static int	ft_ismatch(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* 
#include <stdio.h>

int	main(void)
{
	char	*s1 = "abababababba";
	char	*set = "ab";

	printf("%s\n", ft_strtrim(s1, set));
} */