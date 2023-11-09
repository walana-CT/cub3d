/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:59:20 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/09 14:53:29 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *msg, int err)
{
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(msg, 2);
	return (err);
}

void	free_infos(t_prog *prog)
{
	free(prog->textures.e);
	free(prog->textures.w);
	free(prog->textures.n);
	free(prog->textures.s);
	free(prog->c_color.fullcolor);
	free(prog->f_color.fullcolor);
}

void	c3d_final_free(t_prog *prog)
{
	ft_freetab(prog->map);
	free_infos(prog);
}
