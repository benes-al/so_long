/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft_print_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:00:05 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/03 17:35:09 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_args(const char format, va_list ap)
{
	if (!format)
		return (0);
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_putuint(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_putchar(format));
	return (0);
}
