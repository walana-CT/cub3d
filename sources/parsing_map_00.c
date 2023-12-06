/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:45:14 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:45:15 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @param str A line from the map
 * @return Number of char represing player in the line 
 */
static int	count_player_line(char *str, t_prog *prog)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (*str == 'N' || *str == 'S'
			|| *str == 'E' || *str == 'W')
		{
			c3d_set_player_dir(*str, prog);
			result++;
		}
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
	if (!str)
		return (FALSE);
	while (*str)
	{
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
static void	read_map(t_list **file_lst, t_prog *prog)
{
	t_list	*cur_elem;
	int		player_nbr;

	player_nbr = 0;
	cur_elem = *file_lst;
	while (cur_elem && is_map_line(cur_elem->content))
	{
		player_nbr += count_player_line(cur_elem->content, prog);
		prog->map_height++;
		prog->map_width = ft_max(prog->map_width, ft_strlen(cur_elem->content));
		cur_elem = cur_elem->next;
	}
	if (cur_elem && invalid_line(cur_elem->content))
		exit(c3d_err_msg(EF_WMAP, 1));
	if (player_nbr != 1)
		exit(c3d_err_msg(EF_WMAP, 1));
	if (cur_elem)
		exit(c3d_err_msg(EF_UNEX, 1));
}

/**
 * @param list containg file. At this point only map should remain
 * @param prog ptr to the prog struct
 * extract map from list and verify it is valid
 * @return 0 if succes and 1 if fail 
 */
void	c3d_get_map(t_list **file_lst, t_prog *prog)
{
	if (!file_lst)
		exit(c3d_err_msg(EF_FAT, 1));
	read_map(file_lst, prog);
	c3d_create_map(file_lst, prog);
	c3d_clean_map(prog->map, prog);
	if (!c3d_is_map_closed(prog))
		exit(c3d_err_msg(EF_MOPEN, 1));
}
