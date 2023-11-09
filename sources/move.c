/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/11/09 15:36:12 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_rotateplayer(int32_t mouse_x, t_prog *prog)
{
	int	ret;

	ret = 0;
	prog->player.dir += SENSIVITY * (mouse_x - prog->mouse_x);
	if (prog->player.dir >= M_PI * 2 || prog->player.dir <= -M_PI * 2)
		prog->player.dir = 0;
	if (prog->mouse_x != mouse_x)
		ret = 1;
	prog->mouse_x = mouse_x;
	c3d_refresh(prog);
	return (ret);
}

void	update_coords(float x, float y, t_prog *prog)
{
	prog->player.x = x;
	prog->player.y = y;
}

void	slide_on_x(float dir, float x, t_prog *prog)
{
	if (dir < 0)
		prog->player.y = (int) prog->player.y + prog->size.pl_scale * 0.5;
	else
		prog->player.y = (int) prog->player.y + 0.99 - prog->size.pl_scale * 0.5;
	prog->player.x = x;
}

void	slide_on_y(float dir, float y, t_prog *prog)
{
	if (dir < 0)
		prog->player.x = (int) prog->player.x + prog->size.pl_scale * 0.5;
	else
		prog->player.x = (int) prog->player.x + 0.99 - prog->size.pl_scale * 0.5;
	prog->player.y = y;
}

int	c3d_moveplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	x = prog->player.x + spd * cos(prog->player.dir);
	y = prog->player.y + spd * sin(prog->player.dir);
	if (correct_pos(x, y, prog))
		return (update_coords(x, y, prog), 1);
	if (correct_pos(x, prog->player.y, prog))
		slide_on_x(spd * sin(prog->player.dir), x, prog);
	if (correct_pos(prog->player.x, y, prog))
		slide_on_y(spd * cos(prog->player.dir), y, prog);
	return (1);
}
