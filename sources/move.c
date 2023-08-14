/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/14 16:55:42 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
	printf("dir_x : %f    dir_y : %f\n", targ_x, targ_y);
	prog->player_img->instances[0].x = 10 + prog->player.x * SCALE - (prog->player.size_int/ 2);
	prog->player_img->instances[0].y = 10 + prog->player.y * SCALE - (prog->player.size_int/ 2);
	printf("player update pos %d , %d\n", prog->player_img->instances[0].x, prog->player_img->instances[0].y);
	/*prog->player_img->instances[0].x += dir_x;
	prog->player_img->instances[0].y += dir_y;*/
}
