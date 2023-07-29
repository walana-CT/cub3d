/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:04:26 by rficht            #+#    #+#             */
/*   Updated: 2023/07/29 15:48:49 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	cube2d_init(t_prog *prog)
{
	prog->map = NULL;
	prog->height = 1920;
	prog->lenght = 1080;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_prog	prog;

	cube2d_init(&prog);
	cube2d_parsing(--argc, ++argv, &prog);
	cube2d_instanciate2d(&prog);
	return (0);
}
