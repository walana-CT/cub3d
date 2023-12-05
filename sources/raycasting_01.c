#include <cub3d.h>

static void	casting_00(t_ray *ray)
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
}

static void	casting_01(t_ray *ray, t_prog *prog)
{
	if (ray->map_check.x >= 0 && ray->map_check.x < prog->map_width
		&& ray->map_check.y >= 0 && ray->map_check.y < prog->map_height)
	{
		if (prog->map[ray->map_check.y][ray->map_check.x] == '1'
			|| prog->map[ray->map_check.y][ray->map_check.x] == 'C')
			ray->has_collide = TRUE;
		if (prog->map[ray->map_check.y][ray->map_check.x] == 'C')
			ray->is_door = TRUE;
		else
			ray->is_door = FALSE;
	}	
}

static void	casting_02(t_ray *ray, float r_dir)
{
	ray->intersection.x = ray->start.x + ray->dx * ray->distance;
	ray->intersection.y = ray->start.y + ray->dy * ray->distance;
	if (ray->side == 0)
	{
		ray->screen_dist = (ray->lenght.x - ray->d_step.x) * cos(r_dir);
		if (ray->dx < 0)
			ray->texture_x
				= 1 - fabs((int)ray->intersection.y - ray->intersection.y);
		else
			ray->texture_x
				= fabs(ray->intersection.y - (int)ray->intersection.y);
	}
	else
	{
		ray->screen_dist = (ray->lenght.y - ray->d_step.y) * cos(r_dir);
		if (ray->dy < 0)
			ray->texture_x
				= fabs((int)ray->intersection.x - ray->intersection.x);
		else
			ray->texture_x
				= 1 - fabs(ray->intersection.x - (int)ray->intersection.x);
	}
}

void	c3d_casting(t_ray *ray, t_prog *prog, float r_dir)
{
	t_line		line;

	while (!ray->has_collide)
	{
		casting_00(ray);
		casting_01(ray, prog);
	}
	if (ray->has_collide)
	{
		casting_02(ray, r_dir);
		line = c3d_create_line(prog->player.x * prog->size.mapscale, \
			prog->player.y * prog->size.mapscale, \
			ray->intersection.x * prog->size.mapscale, \
			ray->intersection.y * prog->size.mapscale);
		c3d_draw_line(prog->fov_img, line, VERT);
	}
}

uint32_t	c3d_get_pixel_color(mlx_texture_t *texture, float c_x, float c_y)
{
	int		x;
	int		y;
	uint8_t	c[4];

	x = c_x * texture->width;
	y = c_y * texture->height;
	c[0] = texture->pixels[((x + (y * texture->width)) * 4) + 0];
	c[1] = texture->pixels[((x + (y * texture->width)) * 4) + 1];
	c[2] = texture->pixels[((x + (y * texture->width)) * 4) + 2];
	c[3] = texture->pixels[((x + (y * texture->width)) * 4) + 3];
	return (c[0] << 24 | c[1] << 16 | c[2] << 8 | c[3]);
}
