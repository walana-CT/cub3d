/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlst_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:56:24 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:54:51 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strlst_merge(t_strlist *lst, int str_len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	str = ft_calloc(str_len + 1, sizeof(char));
	if (!str)
		return (0);
	while (lst)
	{
		j = 0;
		while (j < (lst -> str_len))
			str[i++] = (lst -> str[j++]);
		lst = lst ->next;
	}
	return (str);
}
