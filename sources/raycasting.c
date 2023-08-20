/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:04:42 by rficht            #+#    #+#             */
/*   Updated: 2023/08/20 14:55:08 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
# define VERT 0x3568A6FF

static void	cast_init(t_ray *ray, float dx, float dy)
{
	if (dx < 0)
	{
		ray->step.x = -1;
		ray->lenght.x = (ray->start.x - ray->map_check.x) * ray->d_step.x;
	}
	else
	{
		ray->step.x = 1;
		ray->lenght.x = (ray->map_check.x + 1 - ray->start.x) * ray->d_step.x;
	}
	if (dy < 0)
	{
		ray->step.y = -1;
		ray->lenght.y = (ray->start.y - ray->map_check.y) * ray->d_step.y;	
	}
	else
	{
		ray->step.y = 1;
		ray->lenght.y = (ray->map_check.y + 1 - ray->start.y) * ray->d_step.y;
	}
}

static void	casting(t_ray *ray, float dx, float dy, t_prog *prog)
{
	t_line		line;

	while (!ray->has_collide)
	{
		if (ray->lenght.x < ray->lenght.y)
		{
			ray->map_check.x += ray->step.x;
			ray->distance = ray->lenght.x;
			ray->lenght.x += ray->d_step.x;
		}
		else
		{
			ray->map_check.y += ray->step.y;
			ray->distance = ray->lenght.y;
			ray->lenght.y += ray->d_step.y;
		}
		if (ray->map_check.x >= 0 && ray->map_check.x < prog->map_x
			&& ray->map_check.y >= 0 && ray->map_check.y < prog->map_y)
			if (prog->map[ray->map_check.y][ray->map_check.x] == '1')
				ray->has_collide = TRUE;
	}
	if (ray->has_collide)
	{
		ray->intersection.x = ray->start.x + dx * ray->distance;
		ray->intersection.y = ray->start.y + dy * ray->distance;
		line = c3d_create_line(prog->player.x * SCALE, \
			prog->player.y * SCALE, \
			ray->intersection.x * SCALE, \
			ray->intersection.y * SCALE);
		c3d_draw_line(prog->fov_img, line, VERT);
	}
}


void	c3d_cast_one(t_prog *prog, float dx, float dy)
{
	t_ray		ray;

	ray.has_collide = FALSE;
	ray.start.x = prog->player.x;
	ray.start.y = prog->player.y;
	ray.map_check.x = ray.start.x;
	ray.map_check.y = ray.start.y;
	ray.lenght.x = 0;
	ray.lenght.y = 0;
	ray.d_step.x = sqrt(1 + pow((dy / dx), 2));
	ray.d_step.y = sqrt(1 + pow((dx / dy), 2));

	cast_init(&ray, dx, dy);
	casting(&ray, dx, dy, prog);
}
