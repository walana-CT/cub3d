/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:19 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:44:20 by mdjemaa          ###   ########.fr       */
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

void	c3d_refresh(t_prog *prog)
{
	c3d_refresh_fov(prog);
	c3d_refresh_view(prog);
	c3d_dog_anim(prog);
	c3d_raycast(prog);
}

void	c3d_run(t_prog *prog)
{
	mlx_loop_hook(prog->mlx, &c3d_mainhook, prog);
	mlx_key_hook(prog->mlx, &c3d_keyhook, prog);
	mlx_mouse_hook(prog->mlx, &c3d_mousehook, prog);
	mlx_scroll_hook(prog->mlx, &c3d_scrollhook, prog);
	c3d_create_minimap(prog);
	c3d_refresh_fov(prog);
	mlx_loop(prog->mlx);
	mlx_terminate(prog->mlx);
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	check_invalid_args(argc, argv);
	c3d_init(&prog);
	c3d_parsing(--argc, ++argv, &prog);
	c3d_graph_init(&prog);
	printf("Press H for help\n");
	c3d_run(&prog);
	puts("See you");
	c3d_final_free(&prog);
	return (0);
}
