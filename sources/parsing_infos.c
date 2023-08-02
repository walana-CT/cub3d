/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:31:37 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/02 11:50:23 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Map description starts when a line begins with either '1' or ' ' char
int	is_map_desc(char *str)
{
	return (*str == '1' || *str == ' ');
}

/**
 * checks if current line is valid then fills in texture or color
*/
int	get_desc(char *str, t_prog *prog)
{
	if (!str || *str == "\n")
		return (0);
	if (ft_strnstr(str, "NO ", 3))
		return (load_texture(&(prog->textures.n), str + 3));
	if (ft_strnstr(str, "SO ", 3))
		return (load_texture(&(prog->textures.s), str + 3));
	if (ft_strnstr(str, "EA ", 3))
		return (load_texture(&(prog->textures.e), str + 3));
	if (ft_strnstr(str, "WE ", 3))
		return (load_texture(&(prog->textures.o), str + 3));
	if (ft_strnstr(str, "C ", 2))
		return (fill_color(&(prog->c_color.fullcolor), str + 1));
	if (ft_strnstr(str, "F ", 2))
		return (fill_color(&(prog->f_color.fullcolor), str + 1));
	return (1);

}

int	load_texture(mlx_texture_t **texture, char *file)
{
	return (0);
}

/**
 * runs trough list :
 * - If valid indentifier -> extraction
 * - If invalid indentifier -> stop + error
 * - if map or list ends -> stops
*/
int	get_infos(t_list **file, t_prog *prog)
{
	while (*file)
	{
		if (is_map_desc((*file)->content))
			break ;
		if (get_desc((*file)->content, prog))
			return (ft_putstr_fd(EF_BADDESC, 2), 1);
		ft_lstdelone(file, free);
	}
	return (check_info(*prog));
}

/**
 * checks if all the needed infos are present (textures + colors)
 * try to open textures to see if they are valid
 * try to load textures with mlx ?
 * 
*/
int	check_info(t_prog prog)
{
	if (!complete_data(prog))
		return (ft_putstr_fd(EF_MISS, 2), 1);
	return (0);
}