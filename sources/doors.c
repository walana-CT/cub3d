/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:31 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/12 10:29:17 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	c3d_player_facing(float dir)
{
	if (dir < 0)
		dir += 2 * M_PI;
	if (dir < 0.8 || dir > 5.5)
		return ('E');
	if (dir > 0.8 && dir < 2.4)
		return ('S');
	if (dir > 2.4 && dir < 3.9)
		return ('W');
	if (dir > 3.9 && dir < 5.5)
		return ('N');
	return ('!');
}

char	c3d_get_front_tile(t_prog *prog)
{
	int	x;
	int	y;

	x = prog->player.x;
	y = prog->player.y;
	if (c3d_player_facing(prog->player.dir) == 'E')
		return (prog->map[y][x + 1]);
	else if (c3d_player_facing(prog->player.dir) == 'W')
		return (prog->map[y][x -1]);
	else if (c3d_player_facing(prog->player.dir) == 'N')
		return (prog->map[y - 1][x]);
	else if (c3d_player_facing(prog->player.dir) == 'S')
		return (prog->map[y + 1][x]);
	return ('!');
}

void	c3d_set_front_tile(t_prog *prog, char tile)
{
	int	x;
	int	y;

	x = prog->player.x;
	y = prog->player.y;
	if (c3d_player_facing(prog->player.dir) == 'E')
		prog->map[y][x + 1] = tile;
	else if (c3d_player_facing(prog->player.dir) == 'W')
		prog->map[y][x -1] = tile;
	else if (c3d_player_facing(prog->player.dir) == 'N')
		prog->map[y - 1][x] = tile;
	else if (c3d_player_facing(prog->player.dir) == 'S')
		prog->map[y + 1][x] = tile;
}

void	c3d_door_interact(t_prog *prog)
{
	if (c3d_get_front_tile(prog) == 'C')
	{
		c3d_set_front_tile(prog, 'O');
		prog->is_moving = TRUE;
		c3d_create_minimap(prog);
		c3d_refresh(prog);
	}
	else if (c3d_get_front_tile(prog) == 'O')
	{
		c3d_set_front_tile(prog, 'C');
		prog->is_moving = TRUE;
		c3d_create_minimap(prog);
		c3d_refresh(prog);
	}
}
