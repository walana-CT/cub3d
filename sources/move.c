/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/18 16:13:58 by mdjemaa          ###   ########.fr       */
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

int	c3d_moveplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	x = prog->player.x + spd * cos(prog->player.dir);
	y = prog->player.y + spd * sin(prog->player.dir);
	if (correct_pos(x, y, spd, prog))
	{
		prog->player.x = x;
		prog->player.y = y;
		return (1);
	}
	if (correct_pos(x, prog->player.y, spd, prog)) // y est bloque et on slide sur x
	{
		prog->player.x = x; // slide sur x
		if (spd * sin(prog->player.dir) <= 0) // si on essaie de monter, on colle le perso au mur du haut
			prog->player.y = (int) prog->player.y + PLAYER_SCALE * 0.5;
		else // si on essaie de descendre, on colle le perso au mur du haut
			prog->player.y = (int) prog->player.y + 1 - PLAYER_SCALE * 0.5;
	}
	if (correct_pos(prog->player.x, y, spd, prog))
		prog->player.y = y;
	return (1);
}
