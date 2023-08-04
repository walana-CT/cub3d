/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshortenby.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:34:31 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/04 14:13:35 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Replaces the 'cut' ending chars of str with \0
 * Beware of unexpected behaviour if cut > length of str
*/
void	ft_strshortenby(char *str, int cut)
{
	int	last;

	last = ft_sstrlen(str);
	if (!str || last < 0 || cut <= 0)
		return ;
	if (cut > last)
		cut = last;
	while (cut)
	{
		str[--last] = 0;
		cut--;
	}
	return ;
}
