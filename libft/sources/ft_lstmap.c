/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:50:29 by rficht            #+#    #+#             */
/*   Updated: 2022/11/13 16:56:16 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*add_lst;
	void	*new_content;

	if (!lst || !f || !del)
		return (0);
	new_lst = 0;
	while (lst)
	{
		new_content = f(lst -> content);
		add_lst = ft_lstnew(new_content);
		if (!add_lst)
		{
			ft_lstclear(&new_lst, del);
			free(new_content);
		}
		ft_lstadd_back(&new_lst, add_lst);
		lst = lst -> next;
	}
	return (new_lst);
}
