/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/07/31 15:40:07 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cube3d_init(t_prog *prog)
{
	prog->map = NULL;
	prog->textures.e = NULL;
	prog->textures.n = NULL;
	prog->textures.s = NULL;
	prog->textures.o = NULL;
	prog->height = WIN_HEIGHT;
	prog->width = WIN_WIDTH;
	return (0);
}

int	invalid_name(char *arg)
{
	int	n;

	n = -1;
	while (arg[++n])
	{
		if (arg[n] == '.' && arg[n + 1] == 'c'
			&& arg[n + 2] == 'u' && arg[n + 3] == 'b'
			&& !arg[n + 4])
			return (TRUE);
	}
	return (FALSE);
}

void	check_invalid_args(int argc, char *argv[])
{
	if (argc != 1 || invalid_name(*argv))
	{
		ft_putstr_fd("usage : ./cub3d [map.cub]\n", 2);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	check_invalid_args(argc, argv);
	cube3d_init(&prog);
	cube3d_parsing(--argc, ++argv, &prog);
	//cube3d_instanciate2d(&prog);
	return (0);
}
