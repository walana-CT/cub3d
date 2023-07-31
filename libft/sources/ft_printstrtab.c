/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:06 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/07/31 10:33:28 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrtab(char **str_tab, char *titre)
{
	ft_printf(GREEN"--- %s ---\n"RESET, titre);
	while (str_tab && *str_tab)
	{
		ft_printf("%s\n", *str_tab);
		str_tab++;
	}
	ft_printf(GREEN"--- END ---\n"RESET);
}
