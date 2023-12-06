#include "cub3d.h"

int	c3d_rotateplayer(float spd, t_prog *prog)
{
	prog->is_moving = TRUE;
	prog->player.dir += spd;
	if (prog->player.dir >= M_PI * 2 || prog->player.dir <= -M_PI * 2)
		prog->player.dir = 0;
	return (1);
}

int	c3d_mouse_rotate(int32_t mouse_x, t_prog *prog)
{
	prog->player.dir += SENSIVITY * (mouse_x - prog->new_mouse_x);
	if (prog->player.dir >= M_PI * 2 || prog->player.dir <= -M_PI * 2)
		prog->player.dir = 0;
	if (prog->new_mouse_x != mouse_x)
	{
		prog->is_moving = TRUE;
		prog->new_mouse_x = mouse_x;
		return (1);
	}
	return (0);
}
