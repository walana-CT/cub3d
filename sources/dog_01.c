/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:29 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:44:30 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	dog_collision(t_prog *prog)
{
	float	collision_x;
	float	collision_y;

	collision_x = prog->player.x + (cos(prog->player.dir) * 0.5);
	collision_y = prog->player.y + (sin(prog->player.dir) * 0.5);
	if (prog->map[(int) collision_y][(int) collision_x] == '1'
		|| prog->map[(int) collision_y][(int) collision_x] == 'C')
		return (TRUE);
	else
		return (FALSE);
}

static int	dog_anim(t_prog *prog)
{
	if (mlx_get_time() - prog->last_time < 0.1)
		return (1);
	prog->last_time = mlx_get_time();
	if (dog_collision(prog))
	{
		c3d_draw_dog(prog, 13);
		return (1);
	}
	return (0);
}

void	c3d_dog_anim(t_prog *prog)
{
	static int		n;

	if (!prog)
	{
		n = 0;
		return ;
	}
	if (dog_anim(prog))
		return ;
	if (n == 12)
		n = 0;
	else if (prog->is_moving)
		n++;
	else if (!prog->is_moving)
	{
		if (n == 0)
			return ;
		if (n < 6)
			n = 12 - n;
		else
			n++;
	}
	c3d_draw_dog(prog, n);
}
