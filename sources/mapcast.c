/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:04:25 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/23 10:30:04 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_refresh_fov(t_prog *prog)
{
	if (prog->fov_img)
		mlx_delete_image(prog->mlx, prog->fov_img);
	prog->fov_img = mlx_new_image(prog->mlx, prog->w_width, prog->w_height);
	if (!prog->player_img)
		return (1);
	mlx_image_to_window(prog->mlx, prog->fov_img, 0, 0);
	mlx_set_instance_depth(prog->fov_img->instances, 1);
	return (0);
}

void	c3d_raycast(t_prog *prog)
{
	float	camera_x;
	float	camera_step;
	int		n;

	n = -1;
	camera_x = tan(FOV / 2);
	camera_step = camera_x * 2 / WIN_WIDTH;
	camera_x *= -1;
	c3d_refresh_fov(prog);
	while (++n <= WIN_WIDTH)
	{
		c3d_cast_one(prog, cos(prog->player.dir + atan(camera_x)),
			sin(prog->player.dir + atan(camera_x)));
		camera_x += camera_step;
	}
	c3d_cast_one(prog, cos(prog->player.dir), sin(prog->player.dir));
}
