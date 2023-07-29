/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:12:04 by rficht            #+#    #+#             */
/*   Updated: 2022/11/10 15:23:25 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*ptr_str;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		str_len = 0;
	else
		str_len = (int)ft_strlen(s) - start;
	if (str_len > len)
		str_len = len;
	ptr_str = malloc(str_len + 1);
	if (!ptr_str)
		return (0);
	ptr_str[str_len] = '\0';
	while (str_len--)
		ptr_str[str_len] = s[str_len + start];
	return (ptr_str);
}
