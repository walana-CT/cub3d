/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeltop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:14:36 by rficht            #+#    #+#             */
/*   Updated: 2023/08/01 15:29:23 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeltop(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = *lst;
		*lst = temp->next;
		ft_lstdelone(temp, del);
	}
}
