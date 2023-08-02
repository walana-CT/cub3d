/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:53:40 by rficht            #+#    #+#             */
/*   Updated: 2023/08/02 11:58:12 by mdjemaa          ###   ########.fr       */
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
		return (FALSE);
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
	printf("invalid line called on %s\n", str);
	if (!str)
		return (FALSE);
	while (*str)
	{
		printf("looping on %c\n", *str);
		if (*str && ft_is_in(*str, MAP_SYMBOLES) && *str != '\n' && *str != ' ')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

void	clean_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '\n' || map[i][j] == ' ')
				map[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
}

int	read_map(t_list **file_lst, t_prog *prog)
{
	t_list	*cur_elem;

	cur_elem = *file_lst;
	while (cur_elem && is_map_line(cur_elem->content))
	{
		prog->map_y++;
		prog->map_x = ft_max(prog->map_x, ft_strlen(cur_elem->content));
		cur_elem = cur_elem->next;
	}
	if (cur_elem && invalid_line(cur_elem->content))
		return (1);
	return (0);
}

int	create_map(t_list **file_lst, t_prog *prog)
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
	if (!file_lst)
		return (1);
	if (read_map(file_lst, prog))
		return (1);
	printf("\nmap dimensions :	x : %d	y : %d\n", prog->map_x, prog->map_y);
	if (create_map(file_lst, prog))
		return (1);
	ft_lstdel(file_lst, free);
	clean_map(prog->map);
	ft_printstrtab(prog->map, "prog map");
	// if (is_map_closed(prog->map))
	// 	return (1);
	return (0);
}
