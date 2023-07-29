/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:58:37 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:54:52 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlst_len(t_strlist *lst)
{
	int	result;

	result = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		result += lst -> str_len;
		lst = lst -> next;
	}
	return (result);
}
