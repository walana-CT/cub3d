/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:27:57 by rficht            #+#    #+#             */
/*   Updated: 2022/11/01 16:37:31 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset( void *b, int c, size_t count)
{
	unsigned int	n;
	char			*str_b;

	str_b = (char *) b;
	n = 0;
	while (n < count)
			str_b[n++] = (char) c;
	return (b);
}
