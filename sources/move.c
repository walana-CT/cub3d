/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/16 10:30:09 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_rotateplayer(int32_t mouse_x, t_prog *prog)
{
	prog->player.dir += SENSIVITY * (mouse_x - prog->mouse_x);
	if (prog->player.dir >= M_PI * 2 || prog->player.dir <= -M_PI * 2)
		prog->player.dir = 0;
	prog->mouse_x = mouse_x;
	c3d_refresh(prog);
}

void	c3d_moveplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	x = prog->player.x + spd * cos(prog->player.dir);
	y = prog->player.y + spd * sin(prog->player.dir);
	if (!is_pos_ok(x, y, prog))
		return ;
	prog->player.x = x;
	prog->player.y = y;
	c3d_refresh(prog);
}

/*
void	c3d_moveplayer(float dir_y, float dir_x, t_prog *prog)
{
	float	targ_y;
	float	targ_x;

	targ_y = prog->player.y + dir_y;
	targ_x = prog->player.x + dir_x;
	if (!is_pos_ok(targ_x, targ_y, prog))
		return ;
	prog->player.y = targ_y;
	prog->player.x = targ_x;
	printf("dir_x : %f    dir_y : %f\n", targ_x, targ_y);
	c3d_refresh(prog);

	printf("player update pos %d , %d\n", prog->player_img->instances[0].x, prog->player_img->instances[0].y);
	// prog->player_img->instances[0].x += dir_x;
	// prog->player_img->instances[0].y += dir_y;
}
*/