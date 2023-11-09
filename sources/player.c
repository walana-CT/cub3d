/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:41:00 by rficht            #+#    #+#             */
/*   Updated: 2023/11/09 15:37:28 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


static void	c3d_draw_player(t_prog *prog, float size_int)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= size_int)
	{
		j = -1;
		while (++j <= size_int)
		{
			printf("%d %d\n", i, j);
			mlx_put_pixel(prog->player_img, i, j, PLAYER);
		}
	}

}

int	c3d_create_player(t_prog *prog)
{
	if (prog->player_img)
	{
		printf("last image deleted\n");
		mlx_delete_image(prog->mlx, prog->player_img);
	}
	prog->player_img = mlx_new_image(prog->mlx, prog->player.size_int, prog->player.size_int);
	c3d_draw_player(prog, prog->player.size);
	if (!prog->player_img)
		return (1);
	mlx_image_to_window(prog->mlx, prog->player_img,
		prog->player.x * prog->size.mapscale - (prog->player.size_int / 2),
		prog->player.y * prog->size.mapscale - (prog->player.size_int / 2));
	printf("player first pos %f , %f\n", prog->player.x * prog->size.mapscale - (prog->player.size_int / 2), prog->player.y * prog->size.mapscale - (prog->player.size_int / 2));
	mlx_set_instance_depth(prog->player_img->instances, 1);
	return (0);
}
