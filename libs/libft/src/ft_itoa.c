/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:43:15 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/24 18:29:21 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_len(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	itstr(char *str, int len, int n)
{
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		str[len] = '\0';
		len = len - 1;
		while (len > 0)
		{
			str[len] = (n % 10) + 48;
			n = n / 10;
			len--;
		}
		return ;
	}
	str[len] = '\0';
	len = len - 1;
	while (len >= 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = str_len(n);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	itstr(str, len, n);
	return (str);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(1000034));
}*/