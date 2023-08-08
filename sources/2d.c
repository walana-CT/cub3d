/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:32:00 by rficht            #+#    #+#             */
/*   Updated: 2023/08/08 18:50:33 by mdjemaa          ###   ########.fr       */
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

/**
 * Draws a square of side SCALE at coords (x,y)
 * Color to define
*/
void	c3d_map(t_prog *prog)
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
			else if (prog->map[y][x] == '0')
				c3d_drawsquare(*prog, x * SCALE, y * SCALE, WALK);
			else
				c3d_drawsquare(*prog, x * SCALE, y * SCALE, VOID);
		}
	}
}
