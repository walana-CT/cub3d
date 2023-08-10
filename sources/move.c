/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/10 15:38:47 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	c3d_trytomove_right(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)(prog->player.x + prog->player.hb + speed);
	y = (int)prog->player.y;
	if (prog->map[y][x] == '1')
		prog->player.x = x - prog->player.hb;
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.x += speed;
}

void	c3d_trytomove_left(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)(prog->player.x - speed);
	y = (int)prog->player.y;
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.x -= speed;
}

void	c3d_trytomove_up(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)prog->player.x;
	y = (int)(prog->player.y - speed);
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.y -= speed;
}

void	c3d_trytomove_down(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)prog->player.x;
	y = (int)(prog->player.y + speed);
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.y += speed;
}*/

void	c3d_moveplayer(float dir_y, float dir_x, t_prog *prog)
{
	float	targ_y;
	float	targ_x;

	targ_y = prog->player.y + dir_y;
	targ_x = prog->player.x + dir_x;
	if (prog->map[(int) targ_y][(int) targ_x] == '1')
	{
		if (dir_y)
			targ_y = trunc(targ_y);
		else
			targ_x = trunc(targ_x);
	}
	prog->player.y = targ_y;
	prog->player.x = targ_x;
	c3d_draw_minimap_centered(prog);
}
