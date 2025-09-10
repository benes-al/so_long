/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:03:35 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/03 18:21:08 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_puthex(unsigned long int nbr);

int	ft_putptr(void *ptr)
{
	unsigned long int	adress;
	int					count;

	count = 0;
	if (!ptr)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	adress = (unsigned long int)ptr;
	count += ft_putptr_puthex(adress);
	return (count);
}

static int	ft_putptr_puthex(unsigned long int nbr)
{
	const char	*strnbr = "0123456789abcdef";
	int			count;

	count = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr > 15)
		count += ft_putptr_puthex(nbr / 16);
	if (nbr % 16 >= 0 && nbr % 16 <= 9)
		return (count += ft_putchar(strnbr[nbr % 16]));
	else if (nbr % 16 >= 10 && nbr % 16 <= 15)
		return (count += ft_putchar(strnbr[nbr % 16]));
	return (0);
}
