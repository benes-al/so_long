/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benes-al <benes-al@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:57:17 by benes-al          #+#    #+#             */
/*   Updated: 2025/04/24 22:33:36 by benes-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/* 
void	free_node(void *lst)
{
	free(lst);
}

int	main(void)
{
	int *i;
	i = malloc(sizeof(int) * 1);
	i[0] = 2;
	t_list *lst = ft_lstnew(i);
	ft_lstdelone(lst, free_node);
} */