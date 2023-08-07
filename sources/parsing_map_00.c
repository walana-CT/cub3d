/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:53:40 by rficht            #+#    #+#             */
/*   Updated: 2023/08/07 11:58:53 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param str A line from the map
 * @return Number of char represing player in the line 
 */
static int	count_player_line(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (*str == 'N' || *str == 'S'
			|| *str == 'E' || *str == 'O')
			result++;
		str++;
	}
	return (result);
}

/**
 * @param str 
 * verify if the line contains forbidden char for the map
 * @return TRUE of FALSE 
 */
static int	invalid_line(char *str)
{
	printf("invalid line called on %s\n", str);
	if (!str)
		return (FALSE);
	while (*str)
	{
		printf("looping on %c\n", *str);
		if (*str && !ft_is_in(*str, MAP_SYMBOLS) && *str != '\n' && *str != ' ')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

/**
 * @param str evaluted string
 * Determine if a str is a valid format for a map line. check if:
 * - the line contain at least one map char.
 * - the line doesn't contain invalid char.
 * @return TRUE or FALSE 
 * 
 */
static int	is_map_line(char *str)
{
	int	empty;

	empty = TRUE;
	if (!str)
		return (FALSE);
	while (*str)
	{
		if (ft_is_in(*str, MAP_SYMBOLS))
			empty = FALSE;
		else if (*str != '\n' && *str != ' ')
			return (FALSE);
		str++;
	}
	if (empty)
		return (FALSE);
	return (TRUE);
}

/**
 * @param list containg file. At this point only map should remain
 * @param prog ptr to the prog struct
 * browse trough the list to set map values and verify if it is valid
 * @return 0 if succes and 1 if fail 
 */
static int	read_map(t_list **file_lst, t_prog *prog)
{
	t_list	*cur_elem;
	int		player_nbr;

	player_nbr = 0;
	cur_elem = *file_lst;
	while (cur_elem && is_map_line(cur_elem->content))
	{
		player_nbr += count_player_line(cur_elem->content);
		prog->map_y++;
		prog->map_x = ft_max(prog->map_x, ft_strlen(cur_elem->content));
		cur_elem = cur_elem->next;
	}
	if (cur_elem && invalid_line(cur_elem->content))
		return (1);
	if (player_nbr != 1)
		return (1);
	return (0);
}

/**
 * @param list containg file. At this point only map should remain
 * @param prog ptr to the prog struct
 * extract map from list and verify it is valid
 * @return 0 if succes and 1 if fail 
 */
int	c3d_get_map(t_list **file_lst, t_prog *prog)
{
	if (!file_lst)
		return (1);
	if (read_map(file_lst, prog))
		return (1);
	printf("\nmap dimensions :	x : %d	y : %d\n", prog->map_x, prog->map_y);
	if (c3d_create_map(file_lst, prog))
		return (1);
	c3d_clean_map(prog->map, prog);
	if (!c3d_is_map_closed(prog))
	{
		printf("map is not closed\n");
		return (1);
	}
	prog->map[prog->player.pos.y][prog->player.pos.x] = '0';
	ft_printstrtab(prog->map, "prog map");
	return (0);
}

