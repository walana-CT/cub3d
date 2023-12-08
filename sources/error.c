/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:34 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:44:35 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_err_msg(char *msg, int err)
{
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (err);
}

static void	free_textures(t_prog *prog)
{
	int	n;

	n = 0;
	if (prog->textures.e)
		mlx_delete_texture(prog->textures.e);
	if (prog->textures.w)
		mlx_delete_texture(prog->textures.w);
	if (prog->textures.n)
		mlx_delete_texture(prog->textures.n);
	if (prog->textures.s)
		mlx_delete_texture(prog->textures.s);
	mlx_delete_texture(prog->textures.d);
	while (n < 14)
		mlx_delete_texture(prog->dog.textures[n++]);
	free(prog->c_color.fullcolor);
	free(prog->f_color.fullcolor);
}

void	c3d_final_free(t_prog *prog)
{
	ft_freetab(prog->map);
	free_textures(prog);
}
