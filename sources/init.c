/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:39 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/08 10:52:26 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_graph_init(t_prog *prog)
{
	prog->mlx = mlx_init(prog->w_width,
			prog->w_height, "Promenade 3D : Chientown", true);
	if (!prog->mlx)
		exit(c3d_err_msg((char *)mlx_strerror(mlx_errno), 1));
	prog->minimap_img = NULL;
	prog->fov_img = NULL;
	prog->view_img = NULL;
	prog->help_img = NULL;
	prog->last_time = mlx_get_time();
	prog->mouse_x = 0;
	prog->mouse_y = 0;
	prog->new_mouse_x = 0;
	prog->size.minimap_width = 400;
	prog->size.minimap_height = 400 * prog->map_height / prog->map_width;
	prog->size.mapscale = ft_min(400 / prog->map_height, 400 / prog->map_width);
	prog->size.pl_scale = 0.25;
	prog->player.size_int = 1;
	mlx_set_cursor_mode(prog->mlx, MLX_MOUSE_DISABLED);
	c3d_dog_init(prog);
}

void	c3d_init(t_prog *prog)
{
	prog->map = NULL;
	prog->c_color.fullcolor = NULL;
	prog->c_color.color = 0;
	prog->f_color.fullcolor = NULL;
	prog->f_color.color = 0;
	prog->w_height = WIN_HEIGHT;
	prog->w_width = WIN_WIDTH;
	prog->textures.e = NULL;
	prog->textures.n = NULL;
	prog->textures.s = NULL;
	prog->textures.w = NULL;
	prog->map_width = 0;
	prog->map_height = 0;
	prog->run = 1;
	prog->disp_minimap = 1;
	prog->fov = FOV * M_PI / 180;
	prog->mouse_ctrl = 0;
}
