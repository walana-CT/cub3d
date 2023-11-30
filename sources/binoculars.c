#include "cub3d.h"

static mlx_texture_t	*get_next_texture(void)
{
	static char		a = '0';
	char			*file;
	mlx_texture_t	*texture;

	file = ft_strdup("textures/binocularsX.png");
	file[19] = a++;
	if (a > '9')
		a = '0';
	texture = mlx_load_png(file);
	free(file);
	if (!texture)
		exit(c3d_err_msg((char *) mlx_strerror(mlx_errno), 1));
	return (texture);
}

void	c3d_binoculars_anim(t_prog *prog)
{
	mlx_image_t		*old_img;
	mlx_texture_t	*tmp;

	if (mlx_get_time() - prog->last_time < 0.1)
		return ;
	prog->last_time = mlx_get_time();
	tmp = get_next_texture();
	old_img = prog->binoculars_img;
	prog->binoculars_img = mlx_texture_to_image(prog->mlx, tmp);
	if (!prog->binoculars_img)
		exit(c3d_err_msg((char *) mlx_strerror(mlx_errno), 1));
	mlx_image_to_window(prog->mlx, prog->binoculars_img, 0, 0);
	mlx_delete_image(prog->mlx, old_img);
	mlx_delete_texture(tmp);
}

static void	binoculars_on(t_prog *prog)
{
	mlx_texture_t	*tmp;

	if (prog->binoculars_img)
		mlx_delete_image(prog->mlx, prog->binoculars_img);
	tmp = mlx_load_png("textures/binoculars0.png");
	if (!tmp)
		exit(c3d_err_msg((char *)mlx_strerror(mlx_errno), 1));
	prog->binoculars_img = mlx_texture_to_image(prog->mlx, tmp);
	mlx_delete_texture(tmp);
	if (!prog->binoculars_img)
		exit(c3d_err_msg((char *)mlx_strerror(mlx_errno), 1));
	mlx_image_to_window(prog->mlx, prog->binoculars_img, 0, 0);
	prog->minimap_img->enabled = 0;
	prog->binoculars_img->enabled = 1;
}

static void	binoculars_off(t_prog *prog)
{
	prog->minimap_img->enabled = 1;
	prog->binoculars_img->enabled = 0;
}

void	c3d_binoculars(t_prog *prog)
{
	prog->binoculars = (prog->binoculars + 1) % 2;
	if (prog->binoculars)
		binoculars_on(prog);
	else
		binoculars_off(prog);
}
