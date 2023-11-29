#include <cub3d.h>

static uint32_t	get_pixel_color(mlx_texture_t *texture, float c_x, float c_y)
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

void	disp_band(t_prog *prog, t_ray *ray, int x_pos)
{
	int			n;
	int			wall_start;
	int			wall_end;
	int			h;
	float		texture_y;
	uint32_t	pixel_color;

	n = -1;
	h = (WIN_HEIGHT / ray->screen_dist);
	wall_start = -h / 2 + WIN_HEIGHT / 2;
	wall_end = h / 2 + WIN_HEIGHT / 2;
	while (++n < WIN_HEIGHT)
	{
		if (n < wall_start)
			mlx_put_pixel(prog->view_img, x_pos, n, prog->c_color.color);
		else if (n < wall_end)
		{
			texture_y = (float)(n - wall_start) / (float)h;
			if (ray->side == 0)
			{
				if (ray->dx > 0)
					pixel_color = get_pixel_color(prog->textures.w, ray->texture_x, texture_y);
				else
					pixel_color = get_pixel_color(prog->textures.e, ray->texture_x, texture_y);
			}
			else
			{
				if (ray->dy > 0)
					pixel_color = get_pixel_color(prog->textures.s, ray->texture_x, texture_y);
				else
					pixel_color = get_pixel_color(prog->textures.n, ray->texture_x, texture_y);
			}
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
		ray->intersection.x = ray->start.x + ray->dx * ray->distance;
		ray->intersection.y = ray->start.y + ray->dy * ray->distance;
		if (ray->side == 0)
		{
			ray->screen_dist = (ray->lenght.x - ray->d_step.x) * cos(r_dir);
			if (ray->dx < 0)
				ray->texture_x = fabs((int)ray->intersection.y - ray->intersection.y);
			else
				ray->texture_x = fabs(ray->intersection.y - (int)ray->intersection.y);				
		}

		else
		{
			ray->screen_dist = (ray->lenght.y - ray->d_step.y) * cos(r_dir);
			if (ray->dx < 0)
				ray->texture_x = fabs((int)ray->intersection.x - ray->intersection.x);
			else
				ray->texture_x = fabs(ray->intersection.x - (int)ray->intersection.x);
		}

		// if (prog->disp_minimap && !prog->binoculars)
		// {
			line = c3d_create_line(prog->player.x * prog->size.mapscale, \
				prog->player.y * prog->size.mapscale, \
				ray->intersection.x * prog->size.mapscale, \
				ray->intersection.y * prog->size.mapscale);
			c3d_draw_line(prog->fov_img, line, VERT);
		// }
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
