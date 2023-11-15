/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/11/15 11:21:24 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		= prog->player.x * prog->size.mapscale - (prog->player.size_int / 2);
	prog->player_img->instances[0].y
		= prog->player.y * prog->size.mapscale - (prog->player.size_int / 2);
	c3d_refresh_fov(prog);
	c3d_refresh_view(prog);
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
	if (c3d_refresh_fov(prog))
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
		return (c3d_final_free(&prog), 1);
	if (graph_init(&prog) == 0)
		c3d_run(&prog);
	c3d_final_free(&prog);
	puts("CYA");
	return (0);
}
