/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/08/15 18:16:30 by mdjemaa          ###   ########.fr       */
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
	prog->fov_img = NULL;
	prog->mouse_x = 0;
	//prog->player.hb = SCALE / 5.0;
	prog->center.x = MINIMAP_WIDTH / 2;
	prog->center.y = MINIMAP_HEIGHT / 2;
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
	if (c3d_create_minimap(prog))
		exit(1);
	if (c3d_create_player(prog))
		exit(1);
	if (c3d_create_fov(prog))
		exit(1);
	mlx_loop(prog->mlx);
	mlx_terminate(prog->mlx);
	puts("See you");
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	check_invalid_args(argc, argv);
	cub3d_init(&prog);
	if (c3d_parsing(--argc, ++argv, &prog))
		return (1);
	c3d_run(&prog);
	c3d_final_free(&prog);
	puts("CYA");
	return (0);
}
