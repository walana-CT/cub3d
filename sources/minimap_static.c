/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:31:45 by rficht            #+#    #+#             */
/*   Updated: 2023/08/15 16:29:48 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	c3d_drawsquare(t_prog prog, int x, int y, uint32_t col)
{
	int		i;
	t_line	line;

	i = -1;
	while (++i < SCALE)
	{
		line = c3d_create_line(x, y + i, x + SCALE, y + i);
		// if (c3d_lineok(prog, line))
		c3d_draw_line(prog.minimap_img, line, col);
	}
}

int	c3d_create_minimap(t_prog *prog)
{
	int	x;
	int	y;

	if (prog->minimap_img)
		mlx_delete_image(prog->mlx, prog->minimap_img);
	prog->minimap_img = mlx_new_image(prog->mlx, MINIMAP_X, MINIMAP_Y);
	if (!prog->minimap_img)
		return (1);
	y = -1;
	while (++y < prog->map_y)
	{
		x = -1;
		while (++x < prog->map_x)
		{
			if (prog->map[y][x] == '1')
				c3d_drawsquare(*prog, x * SCALE, y * SCALE, WALL);
			else if (ft_is_in(prog->map[y][x], MAP_WALKABLE_SYMBOL))
				c3d_drawsquare(*prog, x * SCALE, y * SCALE, WALK);
		}
	}
	mlx_image_to_window(prog->mlx, prog->minimap_img, 0, 0);
	mlx_set_instance_depth(prog->minimap_img->instances, 0);
	return (0);
}
