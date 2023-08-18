/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:44:51 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/18 15:55:04 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Returns 1 if move is possible
*/
int	correct_pos(float x, float y, float spd, t_prog *prog)
{
	if (spd * cos(prog->player.dir) >= 0)
		x += PLAYER_SCALE * 0.5;
	else
		x -= PLAYER_SCALE * 0.5;
	if (spd * sin(prog->player.dir) >= 0)
		y += PLAYER_SCALE * 0.5;
	else
		y -= PLAYER_SCALE * 0.5;
	return (prog->map[(int)y][(int)x] == '0');
}
