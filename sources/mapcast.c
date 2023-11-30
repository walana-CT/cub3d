#include "cub3d.h"

void	c3d_refresh_fov(t_prog *prog)
{
	if (prog->fov_img)
		mlx_delete_image(prog->mlx, prog->fov_img);
	prog->fov_img = mlx_new_image(prog->mlx, prog->w_width, prog->w_height);
	mlx_image_to_window(prog->mlx, prog->fov_img, 0, 0);
	prog->fov_img->enabled = prog->disp_minimap;
	mlx_set_instance_depth(prog->fov_img->instances, 2);
}

void	c3d_refresh_view(t_prog *prog)
{
	if (prog->view_img)
		mlx_delete_image(prog->mlx, prog->view_img);
	prog->view_img = mlx_new_image(prog->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(prog->mlx, prog->view_img, 0, 0);
	mlx_set_instance_depth(prog->view_img->instances, 0);
}
