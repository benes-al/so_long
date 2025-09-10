/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:10:57 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/19 16:18:44 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*cal;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	cal = malloc(size * nmemb);
	if (!cal)
		return (NULL);
	ft_bzero(cal, (nmemb * size));
	return (cal);
}

/*
int	main(void)
{
	char *cal;
	int	i;

	i = 0;
	printf("%s\n", cal);
	cal = calloc(__INT64_MAX__, 4);
	while (i < 7)
	{
		printf("%i", cal[i]);
		i++;
	}
}*/