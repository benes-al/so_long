/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:26:16 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/25 15:52:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (start > length)
		return (ft_strdup(""));
	if (start + len > length)
	{
		len = length - start;
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int	main(void)
{
	char *str = "girafa";
	
	printf("%s", ft_substr(str, 2, 7));
}*/