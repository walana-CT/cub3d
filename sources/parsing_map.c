/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:53:40 by rficht            #+#    #+#             */
/*   Updated: 2023/08/02 09:52:49 by rficht           ###   ########.fr       */
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

int	invalid_line(char *str)
{
	if (!str)
		return  (FALSE);
	while (*str)
	{
		if (*str && ft_is_in(*str, MAP_SYMBOLES) && *str != '\n' && *str != ' ')
			return (TRUE);
		str++;
	}
	return (FALSE);
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

int	check_map(t_list **file_lst, t_prog *prog)
{
	t_list	*cur_elem;

	cur_elem = *file_lst;
	while (cur_elem && is_map_line(cur_elem->content))
	{
		prog->map_y++;
		prog->map_x = ft_max(prog->map_x, ft_strlen(cur_elem->content));
		cur_elem = cur_elem->next;
	}
	if (invalid_line(cur_elem->content))
		return (1);
	return (0);
}

int create_map(t_list **file_lst, t_prog *prog)
{
	t_list	*cur_elem;
	int		n;

	n = 0;
	cur_elem = *file_lst;
	prog->map = ft_calloc(prog->map_y + 2 , sizeof(char *));
	if (!prog->map)
		return (1);
	while (n < prog->map_y && cur_elem)
	{
		prog->map[n] = ft_calloc(prog->map_x + 1, sizeof(char));
		if (!prog->map[n])
			return (1);
		ft_strlcpy(prog->map[n], cur_elem->content, prog->map_x + 1);
		cur_elem = cur_elem->next;
		n++;
	}
	prog->map[n] = ft_calloc(prog->map_x + 1, sizeof(char));
	if (!prog->map[n])
		return (1);
	return (0);
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
	t_list	*cur_elem;

	if (!file_lst)
		return (1);
	cur_elem = *file_lst;
	if (check_map(file_lst, prog))
		return (1);
	printf("\nmap dimensions :	x : %d	y : %d\n", prog->map_x, prog->map_y);
	if (create_map(file_lst, prog))
		return (1);
	ft_lstdel(file_lst, free);
	replace_spaces(prog->map);
	ft_printstrtab(prog->map, "prog map");
	return (0);
}
