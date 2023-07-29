/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:54:01 by rficht            #+#    #+#             */
/*   Updated: 2022/11/14 10:04:03 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_isinstr(char const c, char const *set)
{
	unsigned int	n;

	n = 0;
	while (set[n])
	{
		if (c == set[n++])
			return (1);
	}
	return (0);
}

static unsigned int	ft_find_start(char const *s1, char const *set)
{
	int	n;

	n = 0;
	while (ft_isinstr(s1[n], set))
		n++;
	return (n);
}

static unsigned int	ft_find_end(char const *s1, char const *set)
{
	int	n;

	n = (int)ft_strlen(s1) - 1;
	if (n > 0)
	{
		while (ft_isinstr(s1[n], set))
			n--;
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str_trim;
	int				trim_end;
	int				trim_start;
	unsigned int	n;

	n = 0;
	if (!s1)
		return (0);
	trim_end = ft_find_end(s1, set);
	trim_start = ft_find_start(s1, set);
	if (trim_start > trim_end)
			str_trim = malloc(sizeof(char));
	else
		str_trim = malloc((trim_end - trim_start + 2) * sizeof(char));
	if (!str_trim)
		return (0);
	while (trim_start <= trim_end)
		str_trim[n++] = s1[trim_start++];
	str_trim[n] = '\0';
	return (str_trim);
}
