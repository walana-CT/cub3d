/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:50:36 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/18 12:11:53 by mdjemaa          ###   ########.fr       */
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
	int		refresh;
	int32_t	mouse_x;
	int32_t	mouse_y;

	prog = (t_prog *) param;
	mouse_x = 0;
	mouse_y = 0;
	mlx_get_mouse_pos(prog->mlx, &mouse_x, &mouse_y);
	fast = 1;
	if (mlx_is_key_down(prog->mlx, MLX_KEY_LEFT_SHIFT))
		fast = 2;
	if (mouse_x != prog->mouse_x)
		refresh = c3d_rotateplayer(mouse_x, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_W))
		refresh = c3d_moveplayer(SPD * fast, prog);
	if (mlx_is_key_down(prog->mlx, MLX_KEY_S))
		refresh = c3d_moveplayer(-SPD * fast, prog);
	if (refresh)
		refresh = c3d_refresh(prog);
}
