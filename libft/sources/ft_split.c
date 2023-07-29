/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:56:26 by rficht            #+#    #+#             */
/*   Updated: 2022/11/12 15:00:49 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	ft_free_tab(char **tab)
{
	unsigned int	n;

	n = 0;
	while (tab[n])
		free(tab[n++]);
	free(tab);
}

static int	ft_get_tab_size(char const *s, char c)
{
	unsigned int	sep_met;
	size_t			tab_size;

	tab_size = 1;
	sep_met = 1;
	while (*s)
	{
		if (*s != c && sep_met)
		{
			tab_size++;
			sep_met = 0;
		}			
		else if (*s == c)
			sep_met = 1;
		s++;
	}
	return (tab_size);
}

static int	ft_fill_tab(char const *s, char c, char **tab, size_t tab_size)
{
	const char		*ptr_str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < (tab_size - 1))
	{
		j = 0;
		while (*s == c && *s)
			s++;
		ptr_str = s;
		while (*ptr_str != c && *ptr_str)
			ptr_str++;
		tab[i] = ft_calloc(ptr_str - s + 1, sizeof(char));
		if (!tab[i])
			return (0);
		while (s != ptr_str)
			tab[i][j++] = *s++;
		i++;
	}
	tab[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_size;

	if (!s)
		return (0);
	tab_size = ft_get_tab_size(s, c);
	tab = malloc(tab_size * sizeof(char *));
	if (!tab)
		return (0);
	if (!ft_fill_tab(s, c, tab, tab_size))
	{
		ft_free_tab(tab);
		return (0);
	}
	return (tab);
}
