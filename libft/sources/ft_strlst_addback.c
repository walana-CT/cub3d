/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:14:52 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:54:55 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_strlst_addback(t_strlist **lst, t_strlist *new)
{
	t_strlist	*last_lst;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_lst = *lst;
	while (last_lst -> next)
		last_lst = last_lst -> next;
	last_lst -> next = new;
}
