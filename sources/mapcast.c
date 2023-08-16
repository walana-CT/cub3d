/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:04:25 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/15 18:42:51 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_create_fov(t_prog *prog)
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
	t_line	line;

	line = c3d_create_line(prog->player.x * SCALE, \
		prog->player.y * SCALE, \
		prog->player.x * SCALE + 10 * cos(prog->player.dir), \
		prog->player.y * SCALE + 10 * sin(prog->player.dir));
	c3d_create_fov(prog);
	c3d_draw_line(prog->fov_img, line, PLAYER);
}
