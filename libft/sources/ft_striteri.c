/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:48 by rficht            #+#    #+#             */
/*   Updated: 2022/11/14 09:57:09 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	n;
	char			*str;

	str = s;
	if (!s || !f)
		return ;
	n = 0;
	while (*s)
	{
		f(n, s);
		n++;
		s++;
	}
	s = str;
}
