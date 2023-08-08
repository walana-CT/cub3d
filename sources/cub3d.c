/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/08/08 19:06:58 by mdjemaa          ###   ########.fr       */
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

void	c3d_run(t_prog *prog)
{
	prog->map_h = SCALE * prog->map_y;
	prog->map_w = SCALE * prog->map_x;
	prog->map_img = mlx_new_image(prog->mlx, prog->map_w, prog->map_h);
	c3d_map(prog);
	mlx_image_to_window(prog->mlx, prog->map_img, 0, 0);
	// mlx_key_hook(prog->mlx, &c3d_keyhook, prog);
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
