/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:44:17 by rficht            #+#    #+#             */
/*   Updated: 2023/12/03 17:21:35 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_textures(t_prog* prog)
{
	int n;

	n = 0;
	prog->dog.textures[0] = mlx_load_png("textures/dog01.png");
	prog->dog.textures[1] = mlx_load_png("textures/dog02.png");
	prog->dog.textures[2] = mlx_load_png("textures/dog03.png");
	prog->dog.textures[3] = mlx_load_png("textures/dog04.png");
	prog->dog.textures[4] = mlx_load_png("textures/dog05.png");
	prog->dog.textures[5] = mlx_load_png("textures/dog06.png");
	prog->dog.textures[6] = mlx_load_png("textures/dog07.png");
	prog->dog.textures[7] = mlx_load_png("textures/dog08.png");
	prog->dog.textures[8] = mlx_load_png("textures/dog09.png");
	prog->dog.textures[9] = mlx_load_png("textures/dog10.png");
	prog->dog.textures[10] = mlx_load_png("textures/dog11.png");
	prog->dog.textures[11] = mlx_load_png("textures/dog12.png");
	prog->dog.textures[12] = mlx_load_png("textures/dog13.png");
	prog->dog.textures[13] = mlx_load_png("textures/dog_paf.png");
	while (n < 14)
	{
		if (!prog->dog.textures[n++])
			exit(1);
	}
}


void	c3d_draw_dog(t_prog *prog, int i)
{
	if (prog->dog.image)
		mlx_delete_image(prog->mlx, prog->dog.image);
	prog->dog.image	= mlx_new_image(prog->mlx, prog->dog.size_x, prog->dog.size_x);
	
	mlx_set_instance_depth

	
}


void c3d_dog_init(t_prog *prog)
{
    init_textures(prog);
	prog->dog.size_x = WIN_WIDTH * DOG_RATIO_X;
	prog->dog.size_y = WIN_HEIGHT * DOG_RATIO_Y;
	prog->dog.pos_x = (WIN_WIDTH - prog->dog.size_x) / 2;
	prog->dog.pos_x = WIN_HEIGHT - prog->dog.size_y;
	prog->dog.image = NULL;
}