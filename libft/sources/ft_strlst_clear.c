/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:42 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:54:54 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlst_clear(t_strlist **lst)
{
	t_strlist	*next_lst;

	if (!lst)
		return (-1);
	while (*lst)
	{
		next_lst = (*lst)-> next;
		ft_strlst_del(*lst);
		*lst = next_lst;
	}
	free (lst);
	return (-1);
}
