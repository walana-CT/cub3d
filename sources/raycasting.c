/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamat <mamat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:04:42 by rficht            #+#    #+#             */
/*   Updated: 2023/11/13 16:33:59 by mamat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
# define VERT 0x3568A6FF


void	disp_band(t_prog *prog, t_ray *ray, int x_pos)
{
	int	n;
	int	wall_start;
	int	wall_end;
	int	h;

	n = -1;
	h = (WIN_HEIGHT / ray->distance);
	wall_start = -h / 2 + WIN_HEIGHT / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = h / 2 + WIN_HEIGHT / 2;
	if (wall_end >= WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	while (++n < wall_start)
		mlx_put_pixel(prog->view_img, x_pos, n, SKY);
	while (++n < wall_end)
	{
		if (ray->lenght.x < ray->lenght.y)
		{
			if (ray->dx > 0)
				mlx_put_pixel(prog->view_img, x_pos, n, EAST_C);
			else
				mlx_put_pixel(prog->view_img, x_pos, n, WEST_C);
		}
		else
		{
			if (ray->dy > 0)
				mlx_put_pixel(prog->view_img, x_pos, n, NORTH_C);
			else
				mlx_put_pixel(prog->view_img, x_pos, n, SOUTH_C);
		}
	}
	while (++n < WIN_HEIGHT)
	{
		mlx_put_pixel(prog->view_img, x_pos, n, GROUND);
	}
}


static void	cast_init(t_ray *ray)
{
	if (ray->dx < 0)
	{
		ray->step.x = -1;
		ray->lenght.x = (ray->start.x - ray->map_check.x) * ray->d_step.x;
	}
	else
	{
		ray->step.x = 1;
		ray->lenght.x = (ray->map_check.x + 1 - ray->start.x) * ray->d_step.x;
	}
	if (ray->dy < 0)
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

static void	casting(t_ray *ray, t_prog *prog)
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
		if (ray->map_check.x >= 0 && ray->map_check.x < prog->map_width
			&& ray->map_check.y >= 0 && ray->map_check.y < prog->map_height)
			if (prog->map[ray->map_check.y][ray->map_check.x] == '1')
				ray->has_collide = TRUE;
	}
	if (ray->has_collide)
	{
		ray->intersection.x = ray->start.x + ray->dx * ray->distance;
		ray->intersection.y = ray->start.y + ray->dy * ray->distance;

		if (prog->disp_minimap && !prog->binoculars)
		{
			line = c3d_create_line(prog->player.x * prog->size.mapscale, \
				prog->player.y * prog->size.mapscale, \
				ray->intersection.x * prog->size.mapscale, \
				ray->intersection.y * prog->size.mapscale);
			c3d_draw_line(prog->fov_img, line, VERT);
		}
	}
}


void	c3d_cast_one(t_prog *prog, float dir, int x_pos)
{
	t_ray		ray;

	ray.has_collide = FALSE;
	ray.dx = cos(dir);
	ray.dy = sin(dir);
	ray.start.x = prog->player.x;
	ray.start.y = prog->player.y;
	ray.map_check.x = ray.start.x;
	ray.map_check.y = ray.start.y;
	ray.lenght.x = 0;
	ray.lenght.y = 0;
	ray.d_step.x = sqrt(1 + pow((ray.dy / ray.dx), 2));
	ray.d_step.y = sqrt(1 + pow((ray.dx / ray.dy), 2));

	cast_init(&ray);
	casting(&ray, prog);
	disp_band(prog, &ray, x_pos);
}
