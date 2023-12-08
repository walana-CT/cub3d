/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:34:06 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/08 12:12:02 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atouc(const char *str)
{
	int	nb;

	if (!str)
		return (-1);
	nb = 0;
	while (nb <= 255 && *str)
	{
		if (*str >= '0' && *str <= '9')
			nb = nb * 10 + *str - 48;
		else
			return (-1);
		str++;
	}
	if (nb >= 0 && nb <= 255)
		return (nb);
	return (-1);
}