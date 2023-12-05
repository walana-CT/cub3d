#include "cub3d.h"

void	c3d_toggle_minimap(t_prog *prog)
{
	prog->disp_minimap = ((prog->disp_minimap + 1) % 2);
	prog->minimap_img->enabled = prog->disp_minimap;
	prog->fov_img->enabled = prog->disp_minimap;
}

void	c3d_toggle_run(t_prog *prog)
{
	if (prog->run == 4)
		prog->run = 1;
	else
		prog->run *= 2;
}
