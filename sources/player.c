/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:41:00 by rficht            #+#    #+#             */
/*   Updated: 2023/08/23 11:27:12 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


static void	c3d_draw_player(t_prog *prog, int size_int)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= size_int)
	{
		j = -1;
		while (++j <= size_int)
			mlx_put_pixel(prog->player_img, i, j, PLAYER);
	}

}

int	c3d_create_player(t_prog *prog)
{
	int	size_int;

	prog->player.size = SCALE * PLAYER_SCALE;
	size_int = (int) prog->player.size;
	if (prog->player_img)
	{
		//printf("last image deleted\n");
		mlx_delete_image(prog->mlx, prog->player_img);
	}
	prog->player_img = mlx_new_image(prog->mlx, size_int, size_int);
	c3d_draw_player(prog, size_int);
	if (!prog->player_img)
		return (1);
	mlx_image_to_window(prog->mlx, prog->player_img,
		prog->player.x * SCALE - (size_int / 2),
		prog->player.y * SCALE - (size_int / 2));
	printf("player first pos %f , %f\n", prog->player.x * SCALE - (size_int / 2), prog->player.y * SCALE - (size_int / 2));
	mlx_set_instance_depth(prog->player_img->instances, 3);
	prog->player.size_int = size_int;
	return (0);
}
