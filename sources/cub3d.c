/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/08/01 15:12:44 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_prog *prog)
{
	prog->map = NULL;
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
	if (argc != 2)
	{
		printf("cub3d: 1 argument is asked\n");
		exit(1);
	}
	else if (invalid_name(*argv))
	{
		printf("cub3d: can only read .cub files\n");
		exit(1);	
	}	
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	check_invalid_args(argc, argv);
	cub3d_init(&prog);
	cub3d_parsing(--argc, ++argv, &prog);
	//cube3d_instanciate2d(&prog);
	return (0);
}
