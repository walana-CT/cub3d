/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:36:46 by rficht            #+#    #+#             */
/*   Updated: 2022/11/02 10:05:50 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_start;

	s_start = s;
	while (*s)
		s++;
	if ((char) c == 0)
		return ((char *) s);
	while (s-- != s_start)
	{
		if (*s == (char) c)
			return ((char *) s);
	}
	return (0);
}
