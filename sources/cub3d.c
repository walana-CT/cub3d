/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/08/15 13:45:22 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_prog *prog)
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
	prog->map_x = 0;
	prog->map_y = 0;
	prog->minimap_img = NULL;
	prog->player_img = NULL;
	prog->player.hb = SCALE / 5.0;
	prog->center.x = MINIMAP_X / 2;
	prog->center.y = MINIMAP_Y / 2;
	prog->mlx = mlx_init(prog->w_width, prog->w_height, "Loup Cailloux", true);
	if (!prog->mlx)
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	return (0);
}

int	is_valid_ext(char *file, char *ext)
{
	while (*file)
		file++;
	if (!ft_strcmp(file - ft_sstrlen(ext), ext))
		return (TRUE);
	return (FALSE);
}

void	check_invalid_args(int argc, char *argv[])
{
	if (argc != 2 || !is_valid_ext(*(++argv), ".cub"))
	{
		ft_putstr_fd("usage : ./cub3d [map.cub]\n", 2);
		exit(1);
	}
}

/*void	c3d_run(t_prog *prog)
{
	prog->minimap_x = SCALE * prog->map_y;
	prog->minimap_y = SCALE * prog->map_x;
	prog->minimap_img = mlx_new_image(prog->mlx, prog->minimap_y, prog->minimap_x);
//	c3d_dispmap(prog);
	c3d_dispplayer(*prog, prog->player);
	mlx_image_to_window(prog->mlx, prog->minimap_img, 0, 0);
	mlx_loop_hook(prog->mlx, &c3d_mainhook, prog);
	mlx_key_hook(prog->mlx, &c3d_keyhook, prog);
	mlx_loop(prog->mlx);
	mlx_terminate(prog->mlx);
	ft_printf("See you");
}*/

/*int	c3d_refresh_minimap(t_prog *prog)
{
	if (prog->minimap_img)
	{
		//printf("last image deleted\n");
		mlx_delete_image(prog->mlx, prog->minimap_img);
	}
	prog->minimap_img =  mlx_new_image(prog->mlx, MINIMAP_X, MINIMAP_Y);
	c3d_draw_minimap_centered(prog);
	if (!prog->minimap_img)
		return (1);
	mlx_image_to_window(prog->mlx, prog->minimap_img, 0, 0);
	return (0);
}*/


int	c3d_refresh(t_prog *prog)
{

	prog->player_img->instances[0].x
		= prog->player.x * SCALE - (prog->player.size_int / 2);
	prog->player_img->instances[0].y
		= prog->player.y * SCALE - (prog->player.size_int / 2);
	c3d_raycast(prog);

	return (0);
}



void	c3d_run(t_prog *prog)
{
	mlx_loop_hook(prog->mlx, &c3d_mainhook, prog);
	mlx_key_hook(prog->mlx, &c3d_keyhook, prog);
	c3d_create_minimap(prog);
	c3d_create_player(prog);
	//c3d_refresh_image(prog);
	mlx_loop(prog->mlx);
	mlx_terminate(prog->mlx);
	ft_printf("See you");
}


int	main(int argc, char *argv[])
{
	t_prog	prog;

	check_invalid_args(argc, argv);
	cub3d_init(&prog);
	if (c3d_parsing(--argc, ++argv, &prog))
		return (/*system("leaks cub3d"), */1);
	c3d_run(&prog);
	// system("leaks cub3d");
	return (0);
}
