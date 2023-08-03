/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:53:40 by rficht            #+#    #+#             */
/*   Updated: 2023/08/03 16:18:06 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_map(char **map)
{
	int n;

	n = 0;
	while (map[n])
	{
		ft_freestr(&map[n]);
		n++;
	}
	free(map);
	return (0);	
}

char **map_dup(t_prog *prog)
{
	int n;
	char **map_cpy;

	n = 0;
	map_cpy = ft_calloc(prog->map_y + 2 , sizeof(char *));
	if (!map_cpy)
		return (NULL);
	while (n < prog->map_y)
	{
		map_cpy[n] = ft_strdup(prog->map[n]);
		if (!prog->map[n])
			return (NULL);
		n++;
	}
	map_cpy[n] = ft_calloc(prog->map_x + 1, sizeof(char));
	if (!prog->map[n])
		return (NULL);
	return (map_cpy);
}

t_vect2d get_player_pos(char ** map)
{
	int			i;
	int			j;
	t_vect2d	result;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			result.x = j;
			result.y = i;
			if (map[i][j] == 'N' || map[i][j]== 'S'
				|| map[i][j] == 'E' || map[i][j] == 'O')
			{

				return (result);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (result);
}

int rec_map_closed(int x, int y, char **map)
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


int	is_map_closed(t_prog *prog)
{
	t_vect2d	player_pos;
	char		**map_cpy;
	int			result;

	player_pos = get_player_pos(prog->map);
	map_cpy = map_dup(prog);
	result = rec_map_closed(player_pos.x, player_pos.y, map_cpy);
	free_map(map_cpy);
	return(result);
}


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
	printf("invalid line called on %s\n", str);
	if (!str)
		return  (FALSE);
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
			if (map[i][j] == '\n'|| map[i][j] == ' ')
				map[i][j] = '0';
			j++;
		}
		j = 0;
		i++;
	}
}

int	count_player_line(char *str)
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

int	read_map(t_list **file_lst, t_prog *prog)
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
	if (!file_lst)
		return (1);
	if (read_map(file_lst, prog))
		return (1);
	printf("\nmap dimensions :	x : %d	y : %d\n", prog->map_x, prog->map_y);
	if (create_map(file_lst, prog))
		return (1);
	clean_map(prog->map);
	ft_printstrtab(prog->map, "prog map");
	if (!is_map_closed(prog))
	{
		printf("map is not closed\n");
		return (1);		
	}
	return (0);
}
