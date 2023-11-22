/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:04:42 by rficht            #+#    #+#             */
/*   Updated: 2023/11/22 10:40:36 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
# define VERT 0x3568A6FF

/*uint32_t	get_pixel_color(mlx_texture_t *texture, float coeff_x, float coeff_y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = coeff_x * texture->width;
	pixel_y = coeff_y * texture->height;
	//printf("color : %d\n", texture->pixels[pixel_x + (pixel_y * texture->height)]);	
	return (texture->pixels[pixel_x + (pixel_y * texture->height)]);
}*/

void	disp_band(t_prog *prog, t_ray *ray, int x_pos)
{
	int		n;
	int		wall_start;
	int		wall_end;
	int		h;

	n = -1;
	h = (WIN_HEIGHT / ray->screen_dist);
	wall_start = -h / 2 + WIN_HEIGHT / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = h / 2 + WIN_HEIGHT / 2;
	if (wall_end >= WIN_HEIGHT)
		wall_end = WIN_HEIGHT;
	while (++n < WIN_HEIGHT)
	{
		if (n < wall_start)
			mlx_put_pixel(prog->view_img, x_pos, n, SKY);
		else if (n < wall_end)
		{
			if (ray->side == 0)
			{
				if (ray->dx > 0)
					mlx_put_pixel(prog->view_img, x_pos, n, NORTH_C);
				else
					mlx_put_pixel(prog->view_img, x_pos, n, SOUTH_C);
			}
			else
			{
				if (ray->dy > 0)
					mlx_put_pixel(prog->view_img, x_pos, n, WEST_C);
				else
					mlx_put_pixel(prog->view_img, x_pos, n, EAST_C);
			}
		}
		else
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

static void	casting(t_ray *ray, t_prog *prog, float r_dir)
{
	t_line		line;

	while (!ray->has_collide)
	{
		if (ray->lenght.x < ray->lenght.y)
		{
			ray->map_check.x += ray->step.x;
			ray->distance = ray->lenght.x;
			ray->lenght.x += ray->d_step.x;
			ray->side = 0;
		}
		else
		{
			ray->map_check.y += ray->step.y;
			ray->distance = ray->lenght.y;
			ray->lenght.y += ray->d_step.y;
			ray->side = 1;
		}
		if (ray->map_check.x >= 0 && ray->map_check.x < prog->map_width
			&& ray->map_check.y >= 0 && ray->map_check.y < prog->map_height)
			if (prog->map[ray->map_check.y][ray->map_check.x] == '1')
				ray->has_collide = TRUE;
	}
	if (ray->has_collide)
	{
		if (ray->side == 0)
			ray->screen_dist = (ray->lenght.x - ray->d_step.x) * cos(r_dir);
		else
			ray->screen_dist = (ray->lenght.y - ray->d_step.y) * cos(r_dir);
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


void	c3d_cast_one(t_prog *prog, float p_dir, float r_dir, int x_pos)
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
	casting(&ray, prog, r_dir);
	disp_band(prog, &ray, x_pos);
}

void	c3d_raycast(t_prog *prog)
{
	float	camera_x;
	float	camera_step;
	int		n;

	n = -1;
	camera_x = tan(FOV / 2);
	camera_step = camera_x * 2 / WIN_WIDTH;
	camera_x *= -1;
	while (++n <= WIN_WIDTH)
	{
		c3d_cast_one(prog, prog->player.dir, atan(camera_x), n);
		camera_x += camera_step;
	}
}
