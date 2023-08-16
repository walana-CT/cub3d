/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:04:42 by rficht            #+#    #+#             */
/*   Updated: 2023/08/16 12:08:43 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


t_vect2D	raycast_x_pos(t_prog *prog, float dx, float dy)
{
	t_vect2D	pos;
	float		s_x;

	s_x = sqrt(1 + (dy / dx));
	pos.x = prog->player.x;
	pos.y = prog->player.y;
	if (pos.x - trunc(pos.x))
	{
		pos.x = trunc(pos.x) + 1;
		pos.y += abs(pos.x - prog->player) * s_x;
	}
	while (!collide_x(pos, dx))
	{
		pos.x += 1;
		pos += s_x;
	}
	return (pos);
}

t_vect2D	raycast_x_neg(t_prog *prog, float dx, float dy)
{
	t_vect2D	pos;
	float		s_x;

	s_x = sqrt(1 + (dy / dx));
	pos.x = prog->player.x;
	pos.y = prog->player.y;
	if (pos.x - trunc(pos.x))
	{
		pos.x = trunc(pos.x);
		pos.y += abs(pos.x - prog->player) * s_x;
	}
	while (!collide_x(pos, dx))
	{
		pos.x -= 1;
		pos += s_x;
	}
	return (pos);
}

t_vect2D	raycast_y_pos(t_prog *prog, float dx, float dy)
{
	t_vect2D	pos;
	float		s_y;

	s_y = sqrt(1 + (dx / dy));
	pos.x = prog->player.x;
	pos.y = prog->player.y;
	if (pos.y - trunc(pos.y))
	{
		pos.y = trunc(pos.y) + 1;
		pos.y += abs(pos.x - prog->player) * s_y;
	}
	while (!collide_y(pos, dy))
	{
		pos.x += 1;
		pos += s_y;
	}
	return (pos);
}

t_vect2D	raycast_y_neg(t_prog *prog, float dx, float dy)
{
	t_vect2D	pos;
	float		s_y;

	s_y = sqrt(1 + (dx / dy));
	pos.x = prog->player.x;
	pos.y = prog->player.y;
	if (pos.y - trunc(pos.y))
	{
		pos.y = trunc(pos.y);
		pos.y += abs(pos.x - prog->player) * s_y;
	}
	while (!collide_y(pos, dy))
	{
		pos.x -= 1;
		pos += s_y;
	}
	return (pos);
}



void	c3d_raycasting(t_prog *prog)
{
	t_ray		ray;
	t_vect2D	x_collide;
	t_vect2D	y_collide;
	float		d_x;
	float		d_y;


	d_x = cos(prog->player.dir);
	d_y = sin(prog->player.dir);
	ray.start.x = prog->player.x;
	ray.start.y = prog->player.y;
	if (d_x >= 0)
		x_collide = raycast_x_pos(prog, dx, dy);
	else
		x_collide = raycast_x_neg(prog, dx, dy);
	if (d_y >= 0)
		y_collide = raycast_y_pos(prog, dx, dy);
	else
		y_collide = raycast_y_neg(prog, dx, dy);
	y_collide = raycast_y(prog);


}
