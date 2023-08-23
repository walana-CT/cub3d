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

int	correct_pos(float x, float y, t_prog *prog)
{
	return (prog->map[(int)(y + PLAYER_SCALE * 0.5)]
			[(int)(x + PLAYER_SCALE * 0.5)] == '0' &&
			prog->map[(int)(y + PLAYER_SCALE * 0.5)]
			[(int)(x - PLAYER_SCALE * 0.5)] == '0' &&
			prog->map[(int)(y - PLAYER_SCALE * 0.5)]
			[(int)(x + PLAYER_SCALE * 0.5)] == '0' &&
			prog->map[(int)(y - PLAYER_SCALE * 0.5)]
			[(int)(x - PLAYER_SCALE * 0.5)] == '0');
}
