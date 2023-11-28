#include "cub3d.h"

int	c3d_rotateplayer(float spd, t_prog *prog)
{
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
		prog->new_mouse_x = mouse_x;
		return (1);
	}
	return (0);
}

void	slide_on_x(float dir, float x, t_prog *prog)
{
	if (dir < 0)
		prog->player.y = (int) prog->player.y + prog->size.pl_scale * 0.5;
	else
		prog->player.y = (int) prog->player.y + 0.99 - prog->size.pl_scale * 0.5;
	prog->player.x = x;
}

void	slide_on_y(float dir, float y, t_prog *prog)
{
	if (dir < 0)
		prog->player.x = (int) prog->player.x + prog->size.pl_scale * 0.5;
	else
		prog->player.x = (int) prog->player.x + 0.99 - prog->size.pl_scale * 0.5;
	prog->player.y = y;
}

int	c3d_moveplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	spd *= prog->run;
	x = prog->player.x + spd * cos(prog->player.dir);
	y = prog->player.y + spd * sin(prog->player.dir);
	if (correct_pos(x, y, prog))
	{
		prog->player.x = x;
		prog->player.y = y;
		return (1);
	}
	if (correct_pos(x, prog->player.y, prog))
		slide_on_x(spd * sin(prog->player.dir), x, prog);
	if (correct_pos(prog->player.x, y, prog))
		slide_on_y(spd * cos(prog->player.dir), y, prog);
	return (1);
}

int	c3d_strafeplayer(float spd, t_prog *prog)
{
	float	x;
	float	y;

	spd *= prog->run;
	x = prog->player.x + spd * cos(prog->player.dir + M_PI_2);
	y = prog->player.y + spd * sin(prog->player.dir + M_PI_2);
	if (correct_pos(x, y, prog))
	{
		prog->player.x = x;
		prog->player.y = y;
		return (1);
	}
	if (correct_pos(x, prog->player.y, prog))
		slide_on_x(spd * sin(prog->player.dir + M_PI_2), x, prog);
	if (correct_pos(prog->player.x, y, prog))
		slide_on_y(spd * cos(prog->player.dir + M_PI_2), y, prog);
	return (1);
}
