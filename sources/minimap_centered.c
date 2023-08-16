/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_centered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:54:38 by rficht            #+#    #+#             */
/*   Updated: 2023/08/16 10:40:01 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_coord	get_map_pos(int y, int x, t_prog *prog)
{
	t_coord	map_pos;
	float		f_pos_x;
	float		f_pos_y;

	f_pos_y = (y - prog->center.y) / SCALE;
	f_pos_x = (x - prog->center.x) / SCALE;
	f_pos_y += prog->player.y;
	f_pos_x += prog->player.x;

	map_pos.y = (int) f_pos_y;
	map_pos.x = (int) f_pos_x;
	return (map_pos);
}



int	is_in_map(int x, int y, t_prog *prog)
{
	if (x < 0 || x > prog->map_x)
		return (FALSE);
	if (y < 0 || y > prog->map_y)
		return (FALSE);
	return (TRUE);
}

void	put_pixel_map(int y, int x, t_prog *prog)
{
	t_coord	map_pos;

	//printf("put_pixel_map x:%d y:%d\n", x, y);
	map_pos = get_map_pos(y, x, prog);
	//printf("pos on the map x:%d y:%d\n", map_pos.x, map_pos.y);
	if (is_in_map(map_pos.x, map_pos.y, prog))
	{	
		//printf("pos val %c\n", prog->map[map_pos.y][map_pos.x]);
		if (prog->map[map_pos.y][map_pos.x] == '0')
			mlx_put_pixel(prog->minimap_img, x, y, WALK);
		if (prog->map[map_pos.y][map_pos.x] == '1')
			mlx_put_pixel(prog->minimap_img, x, y, WALL);
	}
}

void	draw_square_center(t_coord center, int size, t_prog *prog)
{
	int	y;
	int	x;

	if (size % 2 != 0)
		size += 1;
	y = center.y - size / 2;
	x = center.x - size / 2;
	while (y <= center.y + size / 2)
	{
		while (x <= center.x + size / 2)
		{
			//printf("putpixel player %d, %d\n", x , y);
			mlx_put_pixel(prog->minimap_img, x, y, PLAYER);
			x++;
		}
		x = center.x - size / 2;
		y++;
	}
}

void	draw_player_center(t_prog *prog)
{
	t_coord	center;

	center.x = MINIMAP_X / 2;
	center.y = MINIMAP_Y / 2;
	draw_square_center(center, SCALE / 4, prog);
}

void	c3d_draw_minimap_centered(t_prog *prog)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	//mlx_put_pixel(prog->minimap_img, 4, 4, PLAYER);
	printf("map_size %d, %d\n", prog->map_x, prog->map_y);

	while (++y < MINIMAP_Y)
	{
		while (++x < MINIMAP_X)
			put_pixel_map(y, x, prog);
		x = -1;
	}
	draw_player_center(prog);
}
