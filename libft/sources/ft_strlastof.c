/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlastof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:02:45 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/07/31 10:33:28 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns index of last occurence of c in str, or -1
int	ft_strlastof(char *str, char c)
{
	int	i;

	i = ft_sstrlen(str);
	while (--i >= 0)
		if (str[i] == c)
			return (i);
	return (i);
}

// int	main(void)
// {
// 	char	*str = "./script.sh";
// 	int 	i;

// 	i = ft_strlastof(str, '/');
// 	ft_printf("%s\n", ft_substr(str, 0, i));
// 	ft_printf("%s\n", ft_substr(str, i + 1, ft_sstrlen(str) - i));
// 	return (0);
// }