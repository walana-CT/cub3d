/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:52:18 by rficht            #+#    #+#             */
/*   Updated: 2022/11/14 11:36:10 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned char	*str;

	str = (unsigned char *) s;
	while (size--)
	{
		if (*str == (unsigned char) c)
			return ((void *) str);
		str++;
	}
	return (0);
}
