/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/07/31 10:40:36 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cube2d_init(t_prog *prog)
{
	prog->map = NULL;
	prog->height = WIN_HEIGHT;
	prog->width = WIN_WIDTH;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	cube2d_init(&prog);
	cube2d_parsing(--argc, ++argv, &prog);
	//cube2d_instanciate2d(&prog);
	return (0);
}
