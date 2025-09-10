/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:49:19 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/24 19:03:16 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_ln;
	size_t	src_ln;
	size_t	j;

	j = 0;
	src_ln = ft_strlen(src);
	if (!size)
		return (src_ln);
	dst_ln = ft_strlen(dst);
	if (size <= dst_ln)
	{
		return (src_ln + size);
	}
	while (src[j] && (dst_ln + j < size -1))
	{
		dst[dst_ln + j] = src[j];
		j++;
	}
	dst[(dst_ln) + j] = '\0';
	return (src_ln + dst_ln);
}
/* int	main(void)
{
	char dst[11] = "casa";
	char src[5] = "mento";
	size_t size = 11;

	ft_strlcat(dst, src, size);
	printf("%s\n", dst);
} */
