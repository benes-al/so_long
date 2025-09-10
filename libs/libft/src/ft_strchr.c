/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:37:09 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/16 19:47:05 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(const char *s, int c)
{
	int	current_char;

	current_char = 0;
	while (s[current_char] != '\0')
	{
		if ((unsigned char)c == s[current_char])
		{
			return (&((char *)s)[current_char]);
		}
		current_char++;
	}
	if ((unsigned char)c == '\0')
	{
		return (&((char *)s)[current_char]);
	}
	return (NULL);
}
/*
int	main(void)
{
	char s[4] = "casa";

	printf("%s", strchr(s, 'c'));
}*/