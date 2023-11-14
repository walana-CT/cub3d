/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamat <mamat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:44:51 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/11/13 15:10:34 by mamat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_pos(float x, float y, t_prog *prog)
{
	return (ft_is_in(prog->map[(int)(y + prog->size.pl_scale * 0.5)][(int)(x + prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y + prog->size.pl_scale * 0.5)][(int)(x - prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y - prog->size.pl_scale * 0.5)][(int)(x + prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y - prog->size.pl_scale * 0.5)][(int)(x - prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL));
}

