/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:31:45 by rficht            #+#    #+#             */
/*   Updated: 2023/08/14 10:07:13 by rficht           ###   ########.fr       */
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

void	c3d_create_minimap(t_prog *prog)
{
	int	x;
	int	y;


	if (prog->minimap_img)
	{
		//printf("last image deleted\n");
		mlx_delete_image(prog->mlx, prog->minimap_img);
	}
	prog->minimap_img = mlx_new_image(prog->mlx, MINIMAP_X, MINIMAP_Y);
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
			//else
			//	c3d_drawsquare(*prog, x * SCALE, y * SCALE, VOID);
		}
	}
	mlx_image_to_window(prog->mlx, prog->minimap_img, 10, 10);
}
