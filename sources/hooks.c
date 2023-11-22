#include "cub3d.h"

void	toggle_minimap(t_prog *prog)
{
	prog->disp_minimap = ((prog->disp_minimap + 1) % 2);
	prog->minimap_img->enabled = prog->disp_minimap;
	prog->fov_img->enabled = prog->disp_minimap;
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
	int		fast;
	t_prog	*prog;
	int		refresh;

	prog = (t_prog *) param;
	refresh = 0;
	if (prog->binoculars)
		c3d_binoculars_anim(prog);
	mlx_get_mouse_pos(prog->mlx, &prog->mouse_x, &prog->mouse_y);
	fast = 1;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_LEFT_SHIFT))
		fast = 2;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_W))
		refresh += c3d_moveplayer(SPD * fast, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_S))
		refresh += c3d_moveplayer(-SPD * fast, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_A))
		refresh += c3d_strafeplayer(-SPD * fast, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_D))
		refresh += c3d_strafeplayer(SPD * fast, prog);
	if (prog->mouse_x != prog->new_mouse_x)
		refresh += c3d_rotateplayer(prog->mouse_x, prog);
	if (refresh && c3d_refresh(prog))
		mlx_terminate(prog->mlx);
}
