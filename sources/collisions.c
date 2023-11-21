#include "cub3d.h"

int	correct_pos(float x, float y, t_prog *prog)
{
	return (ft_is_in(prog->map[(int)(y + prog->size.pl_scale * 0.5)][(int)(x + prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y + prog->size.pl_scale * 0.5)][(int)(x - prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y - prog->size.pl_scale * 0.5)][(int)(x + prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL) &&
		ft_is_in(prog->map[(int)(y - prog->size.pl_scale * 0.5)][(int)(x - prog->size.pl_scale * 0.5)], MAP_WALKABLE_SYMBOL));
}

