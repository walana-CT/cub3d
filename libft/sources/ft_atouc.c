/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:34:06 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/03 15:05:42 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atouc(const char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && nb <= 255)
		{
			nb = nb * 10 + *str - 48;
			str++;
		}
		else
			return (-1);
	}
	return (nb);
}
