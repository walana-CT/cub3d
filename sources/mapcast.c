/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:04:25 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/20 14:58:11 by rficht           ###   ########.fr       */
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
	int		x = 0;
 	double planeX = 0.0, planeY = 0.66;
	c3d_refresh_fov(prog);
	while (x < WIN_WIDTH)
	{
		double cameraX = 2 * x / (double) WIN_WIDTH - 1; //x-coordinate in camera space
		double rayDirX = cos(prog->player.dir) + planeX * cameraX;
		double rayDirY = sin(prog->player.dir) + planeY * cameraX;
		printf("calling cast one zith %f %f \n",rayDirX, rayDirY);
		c3d_cast_one(prog, rayDirX, rayDirY);
		x++;
	}
	//c3d_cast_one(prog, cos(prog->player.dir), sin(prog->player.dir));
}
