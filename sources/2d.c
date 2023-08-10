/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:32:00 by rficht            #+#    #+#             */
/*   Updated: 2023/08/10 11:02:15 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Just like fdf we will have a mathematical represenation of the
 * independent from display
 * we need to clear dynamics elems et recalculate them every frame:
*/

/**
 * statics elements :
 * walls 
*/

/**
 * dynamics elements :
 * player (position + direction)
 * rays (infos + display) 
 * 
*/

void	c3d_drawplayer(t_prog prog, float x, float y, uint32_t col)
{
	int		i;
	t_line	line;
	int		sx;
	int		sy;

	sx = SCALE * x;
	sy = SCALE * y;
	i = -prog.player.hb -1;
	while (++i < prog.player.hb + 1)
	{
		line = c3d_create_line(sx - prog.player.hb, sy + i, \
			sx + prog.player.hb, sy + i);
		// if (c3d_lineok(prog, line))
		c3d_draw_line(prog.minimap_img, line, col);
	}
}

void	c3d_dispplayer(t_prog prog, t_player p)
{
	c3d_drawplayer(prog, p.x, p.y, PLAYER);
	//c3d_drawfov(*prog);
}

/**
 * Draws a square of side SCALE at coords (x,y)
 * Color to define
*/
void	c3d_drawsquare(t_prog prog, int x, int y, uint32_t col)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < SCALE)
	{
		line = c3d_create_line(x, y + i, x + SCALE, y + i);
		// if (c3d_lineok(prog, line))
		c3d_draw_line(prog.minimap_img, line, col);
	}
}

void	c3d_dispmap(t_prog *prog)
{
	int	x;
	int	y;

	y = -1;
	while (++y < prog->map_y)
	{
		x = -1;
		while (++x < prog->map_x)
		{
			if (prog->map[y][x] == '1')
				c3d_drawsquare(*prog, x * SCALE, y * SCALE, WALL);
			else if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
				c3d_drawsquare(*prog, x * SCALE, y * SCALE, WALK);
			//else
			//	c3d_drawsquare(*prog, x * SCALE, y * SCALE, VOID);
		}
	}
}
