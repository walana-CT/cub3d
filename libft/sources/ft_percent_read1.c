/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_read1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:52:08 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 14:37:52 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_percent_c(t_strlist **lst, char c)
{
	char		*str;
	t_strlist	*new;

	str = calloc(2, sizeof(char));
	if (!str)
		return (0);
	*str = c;
	new = ft_strlst_new(str, 1);
	if (!new)
	{
		free(str);
		return (0);
	}	
	ft_strlst_addback(lst, new);
	return (1);
}

int	ft_percent_s(t_strlist **lst, char *c)
{
	char		*str;
	t_strlist	*new;

	new = 0;
	str = ft_strdup(c);
	if (!str)
		return (0);
	new = ft_strlst_new(str, ft_strlen(str));
	if (!new)
	{
		free(str);
		return (0);
	}	
	ft_strlst_addback(lst, new);
	return (1);
}

int	ft_percent_i(t_strlist **lst, int i)
{
	char		*str;
	t_strlist	*new;

	new = 0;
	str = ft_itoa(i);
	if (!str)
		return (0);
	new = ft_strlst_new(str, ft_strlen(str));
	if (!new)
	{
		free(str);
		return (0);
	}	
	ft_strlst_addback(lst, new);
	return (1);
}

int	ft_percent_u(t_strlist **lst, unsigned int u)
{
	char		*str;
	t_strlist	*new;

	new = 0;
	str = ft_itoa(u);
	if (!str)
		return (0);
	new = ft_strlst_new(str, ft_strlen(str));
	if (!new)
	{
		free(str);
		return (0);
	}	
	ft_strlst_addback(lst, new);
	return (1);
}

int	ft_percent_p(t_strlist **lst, void *ptr)
{
	char		*str;
	t_strlist	*new;

	new = 0;
	str = ft_itohex_ptr(ptr, 0);
	if (!str)
		return (0);
	new = ft_strlst_new(str, ft_strlen(str));
	if (!new)
	{
		free(str);
		return (0);
	}	
	ft_strlst_addback(lst, new);
	return (1);
}
