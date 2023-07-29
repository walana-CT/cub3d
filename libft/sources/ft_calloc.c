/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:28:07 by rficht            #+#    #+#             */
/*   Updated: 2022/11/13 17:00:00 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr_calloc;
	int			n;

	ptr_calloc = malloc(count * size);
	if (!ptr_calloc)
		return (0);
	n = count * size;
	while (n--)
		ptr_calloc[n] = 0;
	return ((void *)ptr_calloc);
}
