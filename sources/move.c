/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/15 10:10:09 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_br(float targ_x, float targ_y, t_prog *prog)
{
	if (prog->map[(int)(targ_y + PLAYER_SCALE / 2)]
		[(int)(targ_x + PLAYER_SCALE / 2)] == '1')
		return (1);
	return (0);
}

int	check_bl(float targ_x, float targ_y, t_prog *prog)
{
	if (prog->map[(int)(targ_y + PLAYER_SCALE / 2)]
		[(int)(targ_x - PLAYER_SCALE / 2)] == '1')
		return (1);
	return (0);
}

int	check_tr(float targ_x, float targ_y, t_prog *prog)
{
	if (prog->map[(int)(targ_y - PLAYER_SCALE / 2)]
		[(int)(targ_x + PLAYER_SCALE / 2)] == '1')
		return (1);
	return (0);
}

int	check_tl(float targ_x, float targ_y, t_prog *prog)
{
	if (prog->map[(int)(targ_y - PLAYER_SCALE / 2)]
		[(int)(targ_x - PLAYER_SCALE / 2)] == '1')
		return (1);
	return (0);
}

int	is_pos_ok(float x, float y, t_prog *prog)
{
	if (check_tl(x, y, prog))
		return (FALSE);
	else if (check_tr(x, y, prog))
		return (FALSE);
	else if (check_bl(x, y, prog))
		return (FALSE);
	else if (check_br(x, y, prog))
		return (FALSE);
	return (TRUE);
}

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
	/*prog->player_img->instances[0].x += dir_x;
	prog->player_img->instances[0].y += dir_y;*/
}
