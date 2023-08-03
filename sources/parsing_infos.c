/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:31:37 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/03 15:37:15 by mdjemaa          ###   ########.fr       */
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
	if (!str || *str == '\n')
		return (0);
	if (ft_strnstr(str, "NO ", 3))
		return (load_texture(&(prog->textures.n), str + 3));
	if (ft_strnstr(str, "SO ", 3))
		return (load_texture(&(prog->textures.s), str + 3));
	if (ft_strnstr(str, "EA ", 3))
		return (load_texture(&(prog->textures.e), str + 3));
	if (ft_strnstr(str, "WE ", 3))
		return (load_texture(&(prog->textures.w), str + 3));
	if (ft_strnstr(str, "C ", 2))
		return (prog->c_color.fullcolor != 0 || \
			load_color(&(prog->c_color), str + 2));
	if (ft_strnstr(str, "F ", 2))
		return (prog->f_color.fullcolor != 0 || \
			load_color(&(prog->f_color), str + 2));
	return (1);
}

int	load_texture(mlx_texture_t **texture, char *file)
{
	ft_strshortenby(file, 1);
	if (*texture)
		return (err_msg(EF_2TEXTURE, 1));
	*texture = mlx_load_png(file);
	if (!*texture)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		return (err_msg(EF_WTEXTURE, 1));
	}
	printf("Loaded texture file : %s\n", file);
	return (0);
}

int	load_color(t_color *color, char *str)
{
	char	**coltab;
	int		i;
	int		col;

	ft_strshortenby(str, 1);
	color->fullcolor = str;
	coltab = ft_split(str, ',');
	if (!coltab)
		return (err_msg(EF_COLOR, 1));
	i = -1;
	while (++i < 3)
	{
		if (coltab[i])
		{
			col = ft_atouc(coltab[i]);
			if (col == -1 || coltab[3])
				return (ft_freetab(coltab), err_msg(EF_COLOR, 2));
			color->col[i] = col;
		}
		else
			return (ft_freetab(coltab), 1);
	}
	color->col[3] = 255;
	return (ft_freetab(coltab), 0);
}

/**
 * checks if all the needed infos are present (textures + colors)
 * try to open textures to see if they are valid
 * try to load textures with mlx ?
 * 
*/
int	check_info(t_prog prog)
{
	(void)prog;
	// if (!complete_data(prog))
	// 	return (err_msg(EF_MISS, 2));
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
	while (*file && !is_map_desc((*file)->content))
	{
		if (get_desc((*file)->content, prog))
			return (err_msg(EF_BADDESC, 2));
		ft_lstdeltop(file, free);
	}
	return (check_info(*prog));
}

