/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:01:20 by rficht            #+#    #+#             */
/*   Updated: 2022/11/08 12:08:27 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_lst;

	if (!lst)
		return (0);
	last_lst = lst;
	while (last_lst -> next)
		last_lst = last_lst -> next;
	return (last_lst);
}
