/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:45:22 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/08 10:57:38 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

uint32_t	get_wall_color(t_prog *prog, t_ray *ray)
{
	if (ray->is_door)
		return (c3d_get_pixel_color
			(prog->textures.d, ray->texture_x, ray->texture_y));
	else if (ray->side == 0)
	{
		if (ray->dx > 0)
			return (c3d_get_pixel_color
				(prog->textures.w, ray->texture_x, ray->texture_y));
		else
			return (c3d_get_pixel_color
				(prog->textures.e, ray->texture_x, ray->texture_y));
	}
	else
	{
		if (ray->dy > 0)
			return (c3d_get_pixel_color
				(prog->textures.s, ray->texture_x, ray->texture_y));
		else
			return (c3d_get_pixel_color
				(prog->textures.n, ray->texture_x, ray->texture_y));
	}
}

void	disp_band(t_prog *prog, t_ray *ray, int x_pos)
{
	int			n;
	int			wall[2];
	int			h;
	uint32_t	pixel_color;

	n = -1;
	h = (WIN_HEIGHT / ray->screen_dist) * ((float)WIN_HEIGHT / WIN_WIDTH);
	wall[0] = -h / 2 + WIN_HEIGHT / 2;
	wall[1] = h / 2 + WIN_HEIGHT / 2;
	while (++n < WIN_HEIGHT)
	{
		if (n < wall[0])
			mlx_put_pixel(prog->view_img, x_pos, n, prog->c_color.color);
		else if (n < wall[1])
		{
			ray->texture_y = (float)(n - wall[0]) / (float)h;
			pixel_color = get_wall_color(prog, ray);
			mlx_put_pixel(prog->view_img, x_pos, n, pixel_color);
		}
		else
			mlx_put_pixel(prog->view_img, x_pos, n, prog->f_color.color);
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

static void	cast_one(t_prog *prog, float p_dir, float r_dir, int x_pos)
{
	t_ray		ray;

	ray.has_collide = FALSE;
	ray.dx = cos(p_dir + r_dir);
	ray.dy = sin(p_dir + r_dir);
	ray.start.x = prog->player.x;
	ray.start.y = prog->player.y;
	ray.map_check.x = ray.start.x;
	ray.map_check.y = ray.start.y;
	ray.lenght.x = 0;
	ray.lenght.y = 0;
	ray.d_step.x = sqrt(1 + pow((ray.dy / ray.dx), 2));
	ray.d_step.y = sqrt(1 + pow((ray.dx / ray.dy), 2));
	cast_init(&ray);
	c3d_casting(&ray, prog, r_dir);
	disp_band(prog, &ray, x_pos);
}

void	c3d_raycast(t_prog *prog)
{
	float	camera_x;
	float	camera_step;
	int		n;

	n = -1;
	camera_x = tan(prog->fov / 2);
	camera_step = camera_x * 2 / WIN_WIDTH;
	camera_x *= -1;
	while (++n < WIN_WIDTH)
	{
		cast_one(prog, prog->player.dir, atan(camera_x), n);
		camera_x += camera_step;
	}
}
