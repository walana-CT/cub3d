/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:00:45 by rficht            #+#    #+#             */
/*   Updated: 2022/11/13 14:27:32 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_lst = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = next_lst;
	}
}
