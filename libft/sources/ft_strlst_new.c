/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:09:29 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:55:15 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_strlist	*ft_strlst_new(char *str, size_t str_len)
{
	t_strlist	*list;

	if (!str)
		return (0);
	list = malloc(sizeof(t_strlist));
	if (list)
	{
		list -> str = str;
		list -> str_len = str_len;
		list -> next = 0;
	}
	return (list);
}
