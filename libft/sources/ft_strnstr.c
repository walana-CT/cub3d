/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:06:08 by rficht            #+#    #+#             */
/*   Updated: 2022/11/14 10:03:38 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check(const char *haystack, const char *needle)
{
	int	n;

	n = 0;
	while (needle[n])
	{
		if (needle[n] != haystack[n])
			return (0);
		n++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	n;

	n = 0;
	if (!len && !haystack)
		return (0);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[n] && (len - n) >= ft_strlen(needle))
	{
		if (haystack[n] == needle[0])
			if (check((haystack + n), needle))
				return ((char *)haystack + n);
		n++;
	}
	return (0);
}
