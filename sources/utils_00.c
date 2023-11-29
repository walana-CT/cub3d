#include "cub3d.h"

int	c3d_correct_pos(float x, float y, t_prog *prog)
{
	return (ft_is_in(prog->map[(int)(y + prog->size.pl_scale * 0.5)]
		[(int)(x + prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y + prog->size.pl_scale * 0.5)]
		[(int)(x - prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y - prog->size.pl_scale * 0.5)]
		[(int)(x + prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y - prog->size.pl_scale * 0.5)]
		[(int)(x - prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL));
}

/**
 * @param map a map
 * allow to free a map and it's content
 * @return 0 To help setting map value
 */
void	c3d_cub_free_map(char **map)
{
	int	n;

	n = 0;
	while (map[n])
	{
		ft_freestr(&map[n]);
		n++;
	}
	free(map);
}

/**
 * @param prog ptr to prog struct
 * @return A copy from the map in it's current state
 */
char	**c3d_map_dup(t_prog *prog)
{
	int		n;
	char	**map_cpy;

	n = 0;
	map_cpy = ft_calloc(prog->map_height + 2, sizeof(char *));
	if (!map_cpy)
		return (NULL);
	while (n < prog->map_height)
	{
		map_cpy[n] = ft_strdup(prog->map[n]);
		if (!prog->map[n])
			return (NULL);
		n++;
	}
	map_cpy[n] = ft_calloc(prog->map_width + 1, sizeof(char));
	if (!prog->map[n])
		return (NULL);
	return (map_cpy);
}

/**
 * @param A map
 * @return player pos in map
 */
t_coord	c3d_get_player_pos(char **map)
{
	int			i;
	int			j;
	t_coord		result;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			result.x = j;
			result.y = i;
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				return (result);
			j++;
		}
		j = 0;
		i++;
	}
	return (result);
}
