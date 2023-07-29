/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:00:33 by rficht            #+#    #+#             */
/*   Updated: 2022/12/10 11:28:41 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char			*dest;
	unsigned int	n;

	n = 0;
	while (s1[n] && n < size)
		n++;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	dest[n] = '\0';
	while (n-- > 0)
		dest[n] = s1[n];
	return (dest);
}
