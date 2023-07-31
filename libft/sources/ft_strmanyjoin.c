/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanyjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:50 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/07/31 10:33:28 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

// join all char* params, last arg MUST be 0 (for some -bad- reason)
char	*ft_strmanyjoin(char *str, ...)
{
	va_list	args;
	char	*ret;
	char	*next;

	ret = ft_strdup(str);
	va_start(args, str);
	next = va_arg(args, char *);
	while (next)
	{
		ret = ft_strfjoin(ret, next);
		next = va_arg(args, char *);
	}
	va_end(args);
	return (ret);
}
/*
int	main(void)
{
	char	*tmp;
	char	*a = "coucou ";
	char	*b = "amis ";

	tmp = ft_strmanyjoin(a, "/", b, " ", b, a, b);
	ft_printf("%s\n", tmp);
	free(tmp);
//	system("leaks a.out");
	return (0);
}
*/