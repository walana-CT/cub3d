/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:50:31 by rficht            #+#    #+#             */
/*   Updated: 2022/11/13 17:10:14 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char			*dest;
	unsigned int	n;

	n = 0;
	while (s1[n])
		n++;
	dest = malloc(sizeof(char) * (n + 1));
	if (dest == 0)
		return (dest);
	dest[n] = '\0';
	while (n-- > 0)
		dest[n] = s1[n];
	return (dest);
}
