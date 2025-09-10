/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:12:57 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/19 15:23:53 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main(void) 
{	
	int fd;

	fd = open("test.txt", O_WRONLY);
	ft_putchar_fd('H', fd);
   	ft_putchar_fd('e', fd);
   	close(fd);
   	return 0;	
}*/
