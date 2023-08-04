/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/08/04 15:38:01 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_prog *prog)
{
	prog->map = NULL;
	prog->c_color.fullcolor = NULL;
	prog->f_color.fullcolor = NULL;
	prog->textures.e = NULL;
	prog->textures.n = NULL;
	prog->textures.s = NULL;
	prog->textures.w = NULL;
	prog->height = WIN_HEIGHT;
	prog->width = WIN_WIDTH;
	prog->map_x = 0;
	prog->map_y = 0;
	prog->mlx = mlx_init(prog->width, prog->height, "Loup Cailloux", false);
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

int	err_msg(char *msg, int err)
{
	ft_putstr_fd(EF_ERR, 2);
	ft_putstr_fd(msg, 2);
	return (err);
}

void	check_invalid_args(int argc, char *argv[])
{
	if (argc != 2 || !is_valid_ext(*(++argv), ".cub"))
	{
		ft_putstr_fd("usage : ./cub3d [map.cub]\n", 2);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	check_invalid_args(argc, argv);
	cub3d_init(&prog);
	if (c3d_parsing(--argc, ++argv, &prog))
		return (1);
	//cube3d_instanciate2d(&prog);
	return (0);
}