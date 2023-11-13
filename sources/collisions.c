/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamat <mamat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:44:51 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/11/13 13:23:07 by mamat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_pos(float x, float y, t_prog *prog)
{ // ! Gerer porte ouverte ('O')
	return (prog->map[(int)(y + prog->size.pl_scale * 0.5)]
			[(int)(x + prog->size.pl_scale * 0.5)] == '0' &&
			prog->map[(int)(y + prog->size.pl_scale * 0.5)]
			[(int)(x - prog->size.pl_scale * 0.5)] == '0' &&
			prog->map[(int)(y - prog->size.pl_scale * 0.5)]
			[(int)(x + prog->size.pl_scale * 0.5)] == '0' &&
			prog->map[(int)(y - prog->size.pl_scale * 0.5)]
			[(int)(x - prog->size.pl_scale * 0.5)] == '0');
}
