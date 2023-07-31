/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:38:43 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/07/31 10:35:40 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	idsize(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	idfill(char *ret, long nb, int size, char signe)
{
	int	i;

	i = 0;
	if (!nb)
		ret[0] = '0';
	while (nb)
	{
		ret[size - 1 + signe - i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (signe)
		ret[0] = '-';
	ret[size + signe] = 0;
}

int	ft_idtoa(int n)
{
	long	nb;
	char	signe;
	char	*ret;

	nb = (long) n;
	signe = 0;
	if (nb < 0)
	{
		signe = 1;
		nb = -nb;
	}
	ret = (char *) malloc(1 + signe + idsize(nb));
	if (!ret)
		return (-1);
	idfill(ret, nb, idsize(nb), signe);
	nb = write(1, ret, ft_sstrlen(ret));
	free(ret);
	return ((int) nb);
}
