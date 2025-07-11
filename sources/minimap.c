/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:48 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:44:49 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	c3d_drawsquare(t_prog prog, int x, int y, uint32_t col)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < prog.size.mapscale)
	{
		line = c3d_create_line(x, y + i, x + prog.size.mapscale, y + i);
		c3d_draw_line(prog.minimap_img, line, col);
	}
}

static void	draw_mapsquare(t_prog *prog, int x, int y)
{
	if (prog->map[y][x] == '1')
		c3d_drawsquare(*prog, x * prog->size.mapscale,
			y * prog->size.mapscale, WALL);
	else if (prog->map[y][x] == '0')
		c3d_drawsquare(*prog, x * prog->size.mapscale,
			y * prog->size.mapscale, WALK);
	else if (prog->map[y][x] == 'C')
		c3d_drawsquare(*prog, x * prog->size.mapscale,
			y * prog->size.mapscale, DOOR);
	else if (prog->map[y][x] == 'O')
		c3d_drawsquare(*prog, x * prog->size.mapscale,
			y * prog->size.mapscale, OP_DOOR);
}

void	c3d_create_minimap(t_prog *prog)
{
	int	x;
	int	y;

	if (prog->minimap_img)
		mlx_delete_image(prog->mlx, prog->minimap_img);
	prog->minimap_img = mlx_new_image(prog->mlx,
			prog->size.minimap_width, prog->size.minimap_height);
	if (!prog->minimap_img)
		exit(c3d_err_msg(EF_FAT, 1));
	y = -1;
	while (++y < prog->map_height)
	{
		x = -1;
		while (++x < prog->map_width)
			draw_mapsquare(prog, x, y);
	}
	mlx_image_to_window(prog->mlx, prog->minimap_img, 0, 0);
	mlx_set_instance_depth(prog->minimap_img->instances, 1);
}
