/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:11:04 by rficht            #+#    #+#             */
/*   Updated: 2023/08/04 15:25:29 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * clean map dependencies that tries to replace a char in a given context
 */
static void	clean_map_replace_empty(char **map, int i, int j, int inside)
{
	if (map[i][j] == '\n' || map[i][j] == ' '
		|| map[i][j] == '0' ||!map[i][j])
	{
		if (inside)
			map[i][j] = '0';
		else
			map[i][j] = ' ';
	}	
}

/**
 * @param list containg file. At this point only map should remain
 * @param prog ptr to the prog struct
 * allocate the map and copy content from the list
 * @return 0 if succes and 1 if fail 
 */
int	c3d_create_map(t_list **file_lst, t_prog *prog)
{
	t_list	*cur_elem;
	int		n;

	n = 0;
	cur_elem = *file_lst;
	prog->map = ft_calloc(prog->map_y + 2, sizeof(char *));
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
 * @param map A map
 * turn the inside ground into 0 and outside into spaces 
 */
void	c3d_clean_map(char **map, t_prog *prog)
{
	int	i;
	int	j;
	int	inside;

	inside = FALSE;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (j < prog->map_x)
		{
			if (map[i][j] == '1' &&
				(map[i][j + 1] == '0' || map[i][j + 1] == ' '))
				c3d_bool_flipflop(&inside);
			clean_map_replace_empty(map, i, j, inside);
			j++;
		}
		j = 0;
		i++;
	}
}

/**
 * @param x player pos in x
 * @param y player pos in y
 * @param ymap a map
 * recursive algorithm thet check if the map is closed
 * @return TRUE or FALSE
 */
int	rec_map_closed(int x, int y, char **map)
{
	map[y][x] = '1';
	if (x == 0 || y == 0 || !map[y + 1][x] || !map[y + 1][x])
		return (FALSE);
	if (map[y + 1][x] == '0')
		if (!rec_map_closed(x, y + 1, map))
			return (FALSE);
	if (map[y - 1][x] == '0')
		if (!rec_map_closed(x, y - 1, map))
			return (FALSE);
	if (map[y][x + 1] == '0')
		if (!rec_map_closed(x + 1, y, map))
			return (FALSE);
	if (map[y][x - 1] == '0')
		if (!rec_map_closed(x - 1, y, map))
			return (FALSE);
	return (TRUE);
}

/**
 * @param ptr to prof struct
 * verify if the map is closed (player cant go out of boundaries)
 * @return TRUE or FALSE
 */
int	c3d_is_map_closed(t_prog *prog)
{
	t_vect2d	player_pos;
	char		**map_cpy;
	int			result;

	player_pos = c3d_get_player_pos(prog->map);
	map_cpy = c3d_map_dup(prog);
	result = rec_map_closed(player_pos.x, player_pos.y, map_cpy);
	c3d_cub_free_map(map_cpy);
	return (result);
}
