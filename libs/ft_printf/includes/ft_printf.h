/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:36:42 by benes-al          #+#    #+#             */
/*   Updated: 2025/05/03 15:47:46 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H  
# define FT_PRINTF_H

//libraries

# include <unistd.h>
# include <stdarg.h>

//prototipe functions

int	ft_printf(const char *format, ...);
int	ft_print_args(const char format, va_list ap);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putuint(unsigned int nbr);
int	ft_puthex(unsigned int nbr, char format);

#endif