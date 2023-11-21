/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:39:49 by rficht            #+#    #+#             */
/*   Updated: 2023/11/11 16:50:57 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>




void	c3d_raycast2(t_prog *prog)
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
	int		x;
	double	raydir_x;
	double	raydir_y;
	
	x = -1;
	plane_x = 0;
	plane_y = 0.66;
	while (++x < WIN_HEIGHT)
	{
		camera_x = 2 * x / (double)WIN_HEIGHT - 1;
		raydir_x = 
	}
	





}