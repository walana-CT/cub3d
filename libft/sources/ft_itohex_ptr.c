/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:14:42 by rficht            #+#    #+#             */
/*   Updated: 2022/12/10 11:25:06 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_nbr_len(unsigned long nbr)
{
	size_t			str_len;

	str_len = 3;
	if (!nbr)
		str_len++;
	while (nbr)
	{
		nbr /= 16;
		str_len++;
	}
	return (str_len);
}

static void	fill_str(unsigned long nbr, size_t str_len, char *str)
{
	str[--str_len] = '\0';
	while (str_len-- > 2)
	{
		str[str_len] = HEX_BASE_LOW[nbr % (16)];
		nbr /= (16);
	}
}

static void	fill_str_up(unsigned long nbr, size_t str_len, char *str)
{
	str[--str_len] = '\0';
	while (str_len-- > 2)
	{
		str[str_len] = HEX_BASE_UP[nbr % (16)];
		nbr /= (16);
	}
}

char	*ft_itohex_ptr(void *ptr, int up)
{
	size_t			str_len;
	char			*str;
	unsigned long	nbr;

	nbr = (unsigned long)ptr;
	str_len = ft_nbr_len(nbr);
	str = ft_calloc(str_len, sizeof(char));
	if (!str)
		return (0);
	if (up)
		fill_str_up(nbr, str_len, str);
	else
		fill_str(nbr, str_len, str);
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
