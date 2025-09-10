/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:04:38 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/03 18:38:58 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char format)
{
	const char	*hex_lowercase = "0123456789abcdef";
	const char	*hex_uppercase = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr > 15)
		count += ft_puthex(nbr / 16, format);
	if (nbr % 16 >= 0 && nbr % 16 <= 9 && format == 'X')
		return (count += ft_putchar(hex_uppercase[nbr % 16]));
	else if (nbr % 16 >= 10 && nbr % 16 <= 15 && format == 'X')
		return (count += ft_putchar(hex_uppercase[nbr % 16]));
	else if (nbr % 16 >= 0 && nbr % 16 <= 9 && format == 'x')
		return (count += ft_putchar(hex_lowercase[nbr % 16]));
	else if (nbr % 16 >= 10 && nbr % 16 <= 15 && format == 'x')
		return (count += ft_putchar(hex_lowercase[nbr % 16]));
	return (0);
}
