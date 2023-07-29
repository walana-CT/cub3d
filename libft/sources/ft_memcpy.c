/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:43:09 by rficht            #+#    #+#             */
/*   Updated: 2022/11/13 17:03:41 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char			*str_dst;
	const char		*str_src;

	if (!dst && !src)
		return (dst);
	str_dst = dst;
	str_src = src;
	while (size--)
		*str_dst++ = *str_src++;
	return (dst);
}
