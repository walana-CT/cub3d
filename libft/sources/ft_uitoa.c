/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:18:06 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/07/31 10:36:40 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ui_fill(char *ret, unsigned int nb, int size)
{
	int	i;

	i = 0;
	if (!nb)
		ret[0] = '0';
	while (nb)
	{
		ret[size - 1 - i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	ret[size] = 0;
}

int	ft_uitoa(unsigned int n)
{
	char	*ret;
	int		len;

	len = idsize(n);
	ret = (char *) malloc(1 + len);
	if (!ret)
		return (-1);
	ui_fill(ret, n, len);
	len = write(1, ret, ft_sstrlen(ret));
	free(ret);
	return (len);
}

int	ft_ctoa(char c)
{
	return (write(1, &c, 1));
}

int	ft_stoa(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_sstrlen(str)));
}
