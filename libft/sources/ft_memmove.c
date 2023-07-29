/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:21:31 by rficht            #+#    #+#             */
/*   Updated: 2022/11/02 08:57:34 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_dst;
	const char	*str_src;

	if (!dst && !src)
		return (dst);
	str_dst = dst;
	str_src = src;
	if (str_dst < str_src)
		while (len--)
			*str_dst++ = *str_src++;
	else
	{
		str_src = src + (len - 1);
		str_dst = dst + (len - 1);
		while (len--)
			*str_dst-- = *str_src--;
	}
	return (dst);
}
