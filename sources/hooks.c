#include "cub3d.h"

void	toggle_minimap(t_prog *prog)
{
	prog->disp_minimap = ((prog->disp_minimap + 1) % 2);
	prog->minimap_img->enabled = prog->disp_minimap;
	prog->fov_img->enabled = prog->disp_minimap;
}

void	toggle_run(t_prog *prog)
{
	if (prog->run == 1)
		prog->run = 2;
	else if (prog->run == 2)
		prog->run = 4;
	else
		prog->run = 1;
}


void	c3d_keyhook(mlx_key_data_t keydata, void *param)
{
	t_prog	*prog;

	prog = (t_prog *) param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		return (mlx_close_window(prog->mlx));
	}
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS && !prog->binoculars)
		toggle_minimap(prog);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		c3d_door_interact(prog);
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		toggle_run(prog);
}

void c3d_mousehook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_prog	*prog;

	(void) mods;
	prog = (t_prog *) param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		printf("Now facing : %c\n", c3d_get_front_tile(prog));
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_PRESS)
		c3d_binoculars(prog);
}

void	c3d_mainhook(void *param)
{
	t_prog	*prog;

	prog = (t_prog *) param;
	if (prog->binoculars)
		c3d_binoculars_anim(prog);
	mlx_get_mouse_pos(prog->mlx, &prog->mouse_x, &prog->mouse_y);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_W))
		c3d_moveplayer(SPD, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_S))
		c3d_moveplayer(-SPD, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_A))
		c3d_strafeplayer(-SPD, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_D))
		c3d_strafeplayer(SPD, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_LEFT))
		c3d_rotateplayer(-SPD, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_RIGHT))
		c3d_rotateplayer(SPD, prog);
	if (prog->mouse_x != prog->new_mouse_x)
		c3d_mouse_rotate(prog->mouse_x, prog);
	if (c3d_refresh(prog))
		mlx_terminate(prog->mlx);
}
