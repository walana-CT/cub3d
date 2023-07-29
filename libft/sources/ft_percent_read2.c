/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_read2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:01:33 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 14:38:44 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_percent_x(t_strlist **lst, unsigned int u, int up)
{
	char		*str;
	t_strlist	*new;

	new = 0;
	str = ft_itohex(u, up);
	if (!str)
		return (0);
	new = ft_strlst_new(str, ft_strlen(str));
	if (!new)
	{
		free(str);
		return (0);
	}	
	ft_strlst_addback(lst, new);
	return (1);
}
