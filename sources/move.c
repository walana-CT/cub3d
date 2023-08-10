/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:54:21 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/10 14:37:37 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_trytomove_right(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)(prog->player.x + prog->player.hb + speed);
	y = (int)prog->player.y;
	if (prog->map[y][x] == '1')
		prog->player.x = x - prog->player.hb;
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.x += speed;
}

void	c3d_trytomove_left(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)(prog->player.x - speed);
	y = (int)prog->player.y;
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.x -= speed;
}

void	c3d_trytomove_up(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)prog->player.x;
	y = (int)(prog->player.y - speed);
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.y -= speed;
}

void	c3d_trytomove_down(t_prog *prog, float speed)
{
	int	x;
	int	y;

	x = (int)prog->player.x;
	y = (int)(prog->player.y + speed);
	if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
		prog->player.y += speed;
}

void	c3d_moveplayer(t_prog *prog)
{
	int		fast;

	fast = 1;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_LEFT_SHIFT))
		fast = 2;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_D))
		c3d_trytomove_right(prog, SPD * fast);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_A))
		c3d_trytomove_left(prog, SPD * fast);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_W))
		c3d_trytomove_up(prog, SPD * fast);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_S))
		c3d_trytomove_down(prog, SPD * fast);
	c3d_dispmap(prog);
	c3d_drawplayer(*prog, prog->player.x, prog->player.y, PLAYER);
}
