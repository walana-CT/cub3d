/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:55:02 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:55:40 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_strlst_read(t_strlist **lst)
{
	t_strlist		*cur_lst;

	if (!lst)
		return ;
	cur_lst = *lst;
	while (cur_lst)
	{
		write(1, cur_lst -> str, cur_lst -> str_len);
		cur_lst = cur_lst -> next;
	}	
}
