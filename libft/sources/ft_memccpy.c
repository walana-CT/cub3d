/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:14:14 by rficht            #+#    #+#             */
/*   Updated: 2022/11/13 17:02:29 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t size)
{
	char			*str_dst;
	const char		*str_src;
	unsigned int	n;

	if (!dst && !src)
		return (dst);
	str_dst = (char *) dst;
	str_src = (const char *) src;
	n = 0;
	while (n < (unsigned int)size)
	{
		if (str_src[n] == (char)c)
		{
			str_dst[n] = str_src[n];
			n++;
			return (dst + n);
		}		
		str_dst[n] = str_src[n];
		n++;
	}
	return (0);
}
