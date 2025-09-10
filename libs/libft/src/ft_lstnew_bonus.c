/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:56:22 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/24 22:00:02 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int	main(void)
{
	t_list	*node1;
	int		*data1;

	data1 = malloc (sizeof(int));
	if(!data1)
		return (1);
	*data1 = 10;
	node1 = ft_lstnew(data1);
	if (node1)
		printf("%d", *(int *)(node1->content));
	free(data1);
	free(node1);
}*/