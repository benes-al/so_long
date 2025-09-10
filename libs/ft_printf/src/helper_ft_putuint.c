/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft_putuint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:02:48 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/03 13:02:59 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_putuint(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}
