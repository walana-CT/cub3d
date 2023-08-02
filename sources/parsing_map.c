/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:53:40 by rficht            #+#    #+#             */
/*   Updated: 2023/08/02 09:16:00 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param str evaluted string
 * Determine if a str is a valid format for a map line. check if:
 * - the line contain at least one map char.
 * - the line does'nt contain invalide char.
 * @return TRUE or FALSE 
 * 
 */
int	is_map_line(char *str)
{
	int	empty;

	empty = TRUE;
	if (!str)
		return  (FALSE);
	while (*str)
	{
		if (ft_is_in(*str, MAP_SYMBOLES))
			empty = FALSE;
		else if (*str != '\n' && *str != ' ')
			return (FALSE);
		str++;
	}
	if (empty)
		return (FALSE);
	return (TRUE);
}

void	replace_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] == ' ')
			map[i][j++] = '0';
		j = 0;
		i++;
	}
}



/**
 * extract map line of list and put them in char array
 * if invalide char -> stop + error
 * if empty line or list end -> stop
 * free list.
 * if no map return error
 */
int	get_map(t_list **file_lst, t_prog *prog)
{
	int		n;
	int 	size_y;
	int		size_x;
	t_list	*cur_elem;

	n = 0;
	size_x = 0;
	size_y = 0;
	if (!file_lst)
		return (1);
	cur_elem = *file_lst;
	
	
	while (cur_elem && is_map_line(cur_elem->content))
	{
		size_x++;
		size_y = ft_max(size_y, ft_strlen(cur_elem->content));
		cur_elem = cur_elem->next;
	}
	printf("\nmap dimensions : %d * %d\n", size_x, size_y);
	prog->map = ft_calloc(size_y + 1 , sizeof(char *));


	cur_elem = *file_lst;
	while (n < size_y && cur_elem)
	{
		prog->map[n] = ft_calloc(size_x + 1, sizeof(char));
		ft_strlcpy(prog->map[n], cur_elem->content, size_x + 1);
		cur_elem = cur_elem->next;
		n++;
	}
	prog->map[n] = ft_calloc(size_x + 1, sizeof(char));
	ft_lstclear(file_lst, free);
	ft_freenull((void **) &file_lst);

	ft_printstrtab(prog->map, "prog map");
	replace_spaces(prog->map);

	return (0);
}
