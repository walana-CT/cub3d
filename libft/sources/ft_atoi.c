/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:49:24 by rficht            #+#    #+#             */
/*   Updated: 2022/11/12 14:24:43 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_get_int(const char *step)
{
	unsigned int	i;
	unsigned int	pow;
	long int		nb;

	i = 0;
	pow = 1;
	nb = 0;
	while (step[i] >= '0' && step[i] <= '9')
		i++;
	while (i > 0)
	{
		i--;
		nb += pow * (step[i] - '0');
		pow *= 10;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	short int	sign;

	sign = 1;
	while (*str)
	{
		if (*str == '+')
			return (ft_get_int(str + 1));
		else if (*str == '-' )
			return (-ft_get_int(str + 1));
		else if (*str >= '0' && *str <= '9')
			return (ft_get_int(str));
		else if ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		else
			return (0);
	}
	return (0);
}
