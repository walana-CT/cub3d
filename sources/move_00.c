/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:50 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:44:51 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	slide_on_x(float dir, float x, t_prog *prog)
{
	if (dir < 0)
		prog->player.y = (int) prog->player.y + prog->size.pl_scale * 0.5;
	else
		prog->player.y = (int) prog->player.y + 0.99
			- prog->size.pl_scale * 0.5;
	prog->player.x = x;
}

static void	slide_on_y(float dir, float y, t_prog *prog)
{
	if (dir < 0)
		prog->player.x = (int) prog->player.x + prog->size.pl_scale * 0.5;
	else
		prog->player.x = (int) prog->player.x + 0.99
			- prog->size.pl_scale * 0.5;
	prog->player.y = y;
}

int	c3d_moveplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	prog->is_moving = TRUE;
	spd *= prog->run;
	x = prog->player.x + spd * cos(prog->player.dir);
	y = prog->player.y + spd * sin(prog->player.dir);
	if (c3d_correct_pos(x, y, prog))
	{
		prog->player.x = x;
		prog->player.y = y;
		return (1);
	}
	if (c3d_correct_pos(x, prog->player.y, prog))
		slide_on_x(spd * sin(prog->player.dir), x, prog);
	if (c3d_correct_pos(prog->player.x, y, prog))
		slide_on_y(spd * cos(prog->player.dir), y, prog);
	return (1);
}

int	c3d_strafeplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	prog->is_moving = TRUE;
	spd *= prog->run;
	x = prog->player.x + spd * cos(prog->player.dir + M_PI_2);
	y = prog->player.y + spd * sin(prog->player.dir + M_PI_2);
	if (c3d_correct_pos(x, y, prog))
	{
		prog->player.x = x;
		prog->player.y = y;
		return (1);
	}
	if (c3d_correct_pos(x, prog->player.y, prog))
		slide_on_x(spd * sin(prog->player.dir + M_PI_2), x, prog);
	if (c3d_correct_pos(prog->player.x, y, prog))
		slide_on_y(spd * cos(prog->player.dir + M_PI_2), y, prog);
	return (1);
}
