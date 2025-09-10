/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:02:14 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/06 13:11:54 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			count = write(1, "-2147483648", 11);
			return (count);
		}
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}
