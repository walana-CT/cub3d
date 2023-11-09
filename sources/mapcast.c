/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:04:25 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/11/09 15:35:47 by rficht           ###   ########.fr       */
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
	mlx_set_instance_depth(prog->fov_img->instances, 2);
	return (0);
}

int	c3d_refresh_view(t_prog *prog)
{
	if (prog->view_img)
		mlx_delete_image(prog->mlx, prog->view_img);
	prog->view_img = mlx_new_image(prog->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!prog->player_img)
		return (1);
	mlx_image_to_window(prog->mlx, prog->view_img, 0, 0);
	mlx_set_instance_depth(prog->view_img->instances, 0);
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
	c3d_refresh_view(prog);
	while (++n <= WIN_WIDTH)
	{
		c3d_cast_one(prog, prog->player.dir + atan(camera_x), n);
		camera_x += camera_step;
	}
	//c3d_cast_one(prog, cos(prog->player.dir), sin(prog->player.dir));
}
