/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:35:41 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/29 10:40:39 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	graph_init(t_prog *prog)
{
	prog->mlx = mlx_init(prog->w_width, prog->w_height, "Loup Cailloux", true);
	if (!prog->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		return (1);
	}
	prog->minimap_img = NULL;
	prog->player_img = NULL;
	prog->fov_img = NULL;
	prog->mouse_x = 0;
	prog->size.minimap_width = 400;
	prog->size.minimap_height = 400 * prog->map_height / prog->map_width;
	prog->size.mapscale = ft_min(400 / prog->map_height, 400 / prog->map_width);
	prog->size.pl_scale = 0.25;
	prog->size.pl_hb = 0.1;
	prog->player.size = prog->size.mapscale * prog->size.pl_scale;
	prog->player.size_int = (int) prog->player.size;
	if (!prog->player.size_int)
		prog->player.size_int = 1;
	printf("size %.2f intsize %d\n", prog->player.size, prog->player.size_int);
	mlx_set_cursor_mode(prog->mlx, MLX_MOUSE_DISABLED);
	return (0);
}

void	cub3d_init(t_prog *prog)
{
	prog->map = NULL;
	prog->c_color.fullcolor = NULL;
	prog->f_color.fullcolor = NULL;
	prog->w_height = WIN_HEIGHT;
	prog->w_width = WIN_WIDTH;
	prog->textures.e = NULL;
	prog->textures.n = NULL;
	prog->textures.s = NULL;
	prog->textures.w = NULL;
	prog->map_width = 0;
	prog->map_height = 0;
}
