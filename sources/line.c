/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:17 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/25 17:16:59 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Draws a line from (a,b) to (c,d)
*/
t_line	c3d_create_line(int a, int b, int c, int d)
{
	t_line	line;

	line.x0 = a;
	line.x1 = c;
	line.y0 = b;
	line.y1 = d;
	line.dx = ft_abs(c - a);
	line.dy = -ft_abs(d - b);
	line.incx = ft_inc_value(a, c);
	line.incy = ft_inc_value(b, d);
	line.err = line.dx + line.dy;
	line.e2 = 0;
	return (line);
}

int	c3d_pixelok(mlx_image_t map_img, t_line line)
{
	if (line.x0 <= 0 || line.x0 >= (int) map_img.width)
		return (0);
	if (line.y0 <= 0 || line.y0 >= (int)map_img.height)
		return (0);
	return (1);
}

int	c3d_lineok(t_prog prog, t_line line)
{
	if (line.x0 < 0 && line.x1 < 0)
		return (0);
	if (line.x0 > prog.size.minimap_height && \
		line.x1 > prog.size.minimap_height)
		return (0);
	if (line.y0 < 0 && line.y1 < 0)
		return (0);
	if (line.y0 > prog.map_height && line.y1 > prog.map_height)
		return (0);
	return (1);
}

//appeler apres test de lineok
void	c3d_draw_line(mlx_image_t *map_img, t_line line, uint32_t col)
{
	while (1)
	{
		if (c3d_pixelok(*map_img, line))
			mlx_put_pixel(map_img, line.x0, line.y0, col);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			line.x0 += line.incx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			line.y0 += line.incy;
		}
	}
}
