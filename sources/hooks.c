#include "cub3d.h"

void	set_images_enabled(t_prog *prog)
{
	prog->player_img->enabled = prog->disp_minimap;
	prog->minimap_img->enabled = prog->disp_minimap;
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
	{
		prog->disp_minimap = ((prog->disp_minimap + 1) % 2);
		set_images_enabled(prog);
	}
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		c3d_door_interact(prog);
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

int	main_subhook(t_prog *prog, int fast)
{
	if (mlx_is_key_down(prog->mlx, MLX_KEY_W))
		return (c3d_moveplayer(SPD * fast, prog));
	if (mlx_is_key_down(prog->mlx, MLX_KEY_S))
		return (c3d_moveplayer(-SPD * fast, prog));
	if (mlx_is_key_down(prog->mlx, MLX_KEY_A))
		return (c3d_strafeplayer(-SPD * fast, prog));
	if (mlx_is_key_down(prog->mlx, MLX_KEY_D))
		return (c3d_strafeplayer(SPD * fast, prog));
	return (0);
}


void	c3d_mainhook(void *param)
{
	int		fast;
	int32_t	mouse_x;
	int32_t	mouse_y;
	t_prog	*prog;
	// int		refresh;

	prog = (t_prog *) param;
	if (prog->binoculars)
		c3d_binoculars_anim(prog);
	mouse_x = 0;
	mouse_y = 0;
	mlx_get_mouse_pos(prog->mlx, &mouse_x, &mouse_y);
	fast = 1;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_LEFT_SHIFT))
		fast = 2;
	if (mouse_x != prog->mouse_x)
		c3d_rotateplayer(mouse_x, prog);
	main_subhook(prog, fast);
	c3d_refresh(prog);
	// refresh = main_subhook(prog);
	// if (refresh && c3d_refresh(prog))
	// 	mlx_terminate(prog->mlx);
}
