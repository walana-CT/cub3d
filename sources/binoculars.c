#include "cub3d.h"

int	c3d_binoculars_anim(t_prog *prog)
{
	mlx_image_t *old_img;
	static char	a = '0';
	char		*file;

	old_img = prog->binoculars_img;
	file = ft_strdup("textures/binoculars0.png");
	file[19] = a++;
	
	prog->binoculars_img = mlx_texture_to_image(prog->mlx, mlx_load_png(file));
	if (!prog->binoculars_img)
		return (1);
	if (a > '9')
		a = '0';
	mlx_image_to_window(prog->mlx, prog->binoculars_img, 0, 0);
	mlx_delete_image(prog->mlx, old_img);
	free(file);
	return (0);
}

int	binoculars_on(t_prog *prog)
{
	if (prog->binoculars_img)
		mlx_delete_image(prog->mlx, prog->binoculars_img);
	prog->binoculars_img = mlx_texture_to_image(prog->mlx, mlx_load_png("textures/binoculars0.png"));
	if (!prog->binoculars_img)
		return (1);	 
	mlx_image_to_window(prog->mlx, prog->binoculars_img, 0, 0);
	prog->player_img->enabled = 0;
	prog->minimap_img->enabled = 0;
	prog->binoculars_img->enabled = 1;
	return (0);
}



int	binoculars_off(t_prog *prog)
{
	prog->player_img->enabled = 1;
	prog->minimap_img->enabled = 1;
	prog->binoculars_img->enabled = 0;
	return (0);
}

int	c3d_binoculars(t_prog *prog)
{
	prog->binoculars = (prog->binoculars+ 1) % 2;
	if (prog->binoculars)
		return (binoculars_on(prog));
	else
		return (binoculars_off(prog));
}
