/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infos_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:08:39 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/07 18:43:42 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Map description starts when a line begins with either '1' or ' ' char
int	is_map_desc(char *str)
{
	return (*str == '1' || *str == ' ');
}

int	color_ok(t_color color)
{
	if (!color.fullcolor)
		return (0);
	if (!ft_isuchar(color.col[0]) || !ft_isuchar(color.col[1]) || \
		!ft_isuchar(color.col[2]) || !ft_isuchar(color.col[3]))
		return (0);
	return (1);
}

/**
 * checks if all the needed infos are present (textures + colors)
 * try to open textures to see if they are valid
 * try to load textures with mlx ?
 * 
*/
int	check_info(t_prog prog)
{
	if (!color_ok(prog.c_color) || !color_ok(prog.f_color))
		return (err_msg(EF_MISS, 2));
	ft_printf("Loaded floor color \t%s\n", prog.f_color.fullcolor);
	ft_printf("Loaded ceiling color \t%s\n", prog.c_color.fullcolor);
	if (!prog.textures.n || !prog.textures.s || \
		!prog.textures.e ||!prog.textures.w)
		return (err_msg(EF_MISS, 2));
	return (0);
}
