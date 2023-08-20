/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:04:42 by rficht            #+#    #+#             */
/*   Updated: 2023/08/20 12:46:14 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
# define VERT 0x3568A6FF
# define HORI 0xc91616FF

void	c3d_raycasting(t_prog *prog)
{
	t_line		line;
	t_vect2d	ray_start;
	
	float		dx;
	float		dy;
	
	t_vect2d	ray_unit_step_size;

	t_vect2d	step;
	t_coord		map_check;
	t_vect2d	raylenght;

	float		distance = 0;
	float		maxdist = 500.0;
	int			has_collide = FALSE;

	t_vect2d	intersection;

	ray_start.x = prog->player.x;
	ray_start.y = prog->player.y;
	map_check.x = ray_start.x;
	map_check.y = ray_start.y;
	raylenght.x = 0;
	raylenght.y = 0;
	dx = cos(prog->player.dir);
	dy = sin(prog->player.dir);
	ray_unit_step_size.x = sqrt(1 + pow((dy / dx), 2));
	ray_unit_step_size.y = sqrt(1 + pow((dx / dy), 2));


	printf("raycasting pos %f %f direction %f\n", prog->player.x, prog->player.y, prog->player.dir);
	printf("ray unit step size x\n", ray_unit_step_size.x);
	printf("ray unit step size y\n", ray_unit_step_size.y);	
	if (dx < 0)
	{
		step.x = -1;
		raylenght.x = (ray_start.x - map_check.x) * ray_unit_step_size.x;
		printf("offset x found : %f\n", (ray_start.x - map_check.x));		
	}
	else
	{
		step.x = 1;
		raylenght.x = ( map_check.x + 1 - ray_start.x) * ray_unit_step_size.x;
		printf("offset x found : %f\n", (ray_start.x - map_check.x));	
	}
	if (dy < 0)
	{
		step.y = -1;
		raylenght.y = (ray_start.y - map_check.y) * ray_unit_step_size.y;
		printf("offset x found : %f\n", (ray_start.x - map_check.x));		
	}
	else
	{
		step.y = 1;
		raylenght.y = (map_check.y + 1 - ray_start.y) * ray_unit_step_size.y;
		printf("offset x found : %f\n", (ray_start.x - map_check.x));	
	}

	while (!has_collide && distance < maxdist)
	{
		if (raylenght.x < raylenght.y)
		{
			map_check.x += step.x;
			distance = raylenght.x;
			raylenght.x += ray_unit_step_size.x;
		}
		else
		{
			map_check.y += step.y;
			distance = raylenght.y;
			raylenght.y += ray_unit_step_size.y;			
		}
		if (map_check.x > 0 && map_check.x < prog->map_x && map_check.y > 0 && map_check.y < prog->map_y)
			if (prog->map[map_check.y][map_check.x])
				has_collide = TRUE;
	}
	if (has_collide)
	{
		intersection.x = ray_start.x + dx * distance;
		intersection.y = ray_start.y + dy * distance;
		line = c3d_create_line(prog->player.x * SCALE, \
			prog->player.y * SCALE, \
			intersection.x * SCALE, \
			intersection.y * SCALE);
		c3d_draw_line(prog->fov_img, line, VERT);
	}




}
