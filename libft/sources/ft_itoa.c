/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:25:23 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:54:03 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_nbr_len(long int n)
{
	long long int	nbr_cpy;
	long long int	pwr;
	size_t			str_len;

	str_len = 2;
	pwr = 10;
	nbr_cpy = n;
	if (nbr_cpy < 0)
	{
		nbr_cpy *= -1;
		str_len++;
	}
	while (pwr <= nbr_cpy)
	{
		pwr *= 10;
		str_len++;
	}
	return (str_len);
}

static void	fill_str(long int n, size_t str_len, char *str)
{
	str[--str_len] = '\0';
	if (n < 0)
	{
		while (str_len-- > 1)
		{
			str[str_len] = '0' - n % (10);
			n /= (10);
		}
		str[str_len] = '-';
	}
	else
	{
		while (str_len-- > 1)
		{
			str[str_len] = '0' + n % (10);
			n /= (10);
		}
		str[str_len] = '0' + n % (10);
	}
}

char	*ft_itoa(long int n)
{
	size_t		str_len;
	char		*str;

	str_len = ft_nbr_len(n);
	str = malloc(str_len);
	if (!str)
		return (0);
	fill_str(n, str_len, str);
	return (str);
}
