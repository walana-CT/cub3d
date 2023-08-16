/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:44:51 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/15 13:45:30 by mdjemaa          ###   ########.fr       */
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
