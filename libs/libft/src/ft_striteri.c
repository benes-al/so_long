/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:01:25 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/19 11:40:12 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	str_toupper(unsigned int i, char *str)
{
	i = 0;
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
}

int	main(void)
{
	char str[] = "casa";

	printf("Before: %s\n", str);
	ft_striteri(str, str_toupper);
	printf("After: %s\n", str);
	return (0);
}*/