/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:50:36 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/14 17:00:12 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_keyhook(mlx_key_data_t keydata, void *param)
{
	t_prog	*prog;

	prog = (t_prog *) param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(prog->mlx);
		return ;
	}
}

void	c3d_mainhook(void *param)
{
	t_prog	*prog;
	int		fast;

	prog = (t_prog *) param;
	fast = 1;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_LEFT_SHIFT))
		fast = 2;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_D))
		c3d_moveplayer(0, SPD * fast, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_A))
		c3d_moveplayer(0, -SPD * fast, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_W))
		c3d_moveplayer(-SPD * fast, 0, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_S))
		c3d_moveplayer(SPD * fast, 0, prog);
}
