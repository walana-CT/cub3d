/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:44:51 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/11/09 15:34:52 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_pos(float x, float y, t_prog *prog)
{
	return (prog->map[(int)(y + prog->size.pl_scale * 0.5)]
			[(int)(x + prog->size.pl_scale * 0.5)] == '0' &&
			prog->map[(int)(y + prog->size.pl_scale * 0.5)]
			[(int)(x - prog->size.pl_scale * 0.5)] == '0' &&
			prog->map[(int)(y - prog->size.pl_scale * 0.5)]
			[(int)(x + prog->size.pl_scale * 0.5)] == '0' &&
			prog->map[(int)(y - prog->size.pl_scale * 0.5)]
			[(int)(x - prog->size.pl_scale * 0.5)] == '0');
}
