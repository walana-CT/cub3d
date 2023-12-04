#include "cub3d.h"

void	c3d_scrollhook(double xdelta, double ydelta, void *param)
{
	t_prog	*prog;

	(void) xdelta;
	prog = (t_prog *) param;
	if (ydelta < 0 && prog->fov > 0.11)
		prog->fov -= 0.1;
	if (ydelta > 0 && prog->fov < 3.03)
		prog->fov += 0.1;
	printf("FOV now : %f\n", prog->fov * 180 / 3.14);
}

void	c3d_keyhook(mlx_key_data_t keydata, void *param)
{
	t_prog	*prog;

	prog = (t_prog *) param;
	if (keydata.key == MLX_KEY_ESCAPE)
		return (mlx_close_window(prog->mlx));
	if (keydata.key == MLX_KEY_BACKSPACE)
		prog->fov = FOV;
	if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS
		&& !prog->binoculars)
		c3d_toggle_minimap(prog);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		c3d_door_interact(prog);
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		c3d_toggle_run(prog);
}

void	c3d_mousehook(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_prog	*prog;
	int		mouse_x;
	int		mouse_y;

	(void) mods;
	prog = (t_prog *) param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		printf("Now facing : %c\n", c3d_get_front_tile(prog));
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_PRESS)
		c3d_binoculars(prog);
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		prog->mouse_ctrl = ((prog->mouse_ctrl + 1) % 2);
		mlx_get_mouse_pos(prog->mlx, &mouse_x, &mouse_y);
		prog->new_mouse_x = mouse_x;
	}
}

void	c3d_mainhook(void *param)
{
	t_prog	*prog;

	prog = (t_prog *) param;
	prog->is_moving = 0;
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
	if (prog->mouse_ctrl && prog->mouse_x != prog->new_mouse_x)
		c3d_mouse_rotate(prog->mouse_x, prog);
	c3d_refresh(prog);
}
