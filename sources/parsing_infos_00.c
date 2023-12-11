/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_infos_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:44:57 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/08 13:32:13 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture(mlx_texture_t **texture, char *file)
{
	while (*file == ' ')
		file++;
	ft_strshortenby(file, 1);
	if (*texture)
		exit(c3d_err_msg(EF_2TEXTURE, 1));
	*texture = mlx_load_png(file);
	if (!*texture)
		exit(c3d_err_msg((char *)mlx_strerror(mlx_errno), 1));
}

static void	null_str_if_empty(char **str)
{
	ft_strshortenby(*str, 1);
	if (!ft_strcmp(*str, ""))
		*str = NULL;
}

static void	load_color(t_color *color, char *str)
{
	char	**coltab;
	int		i;
	int		col;

	if (color->fullcolor)
		exit(c3d_err_msg(EF_BADDESC, 1));
	null_str_if_empty(&str);
	c3d_commascheck(str);
	while (*str == ' ')
		str++;
	color->fullcolor = ft_strdup(str);
	coltab = ft_split(str, ',');
	if (!coltab)
		exit(c3d_err_msg(EF_COLOR, 1));
	i = -1;
	while (++i < 3)
	{
		col = ft_atouc(coltab[i]);
		if (col == -1)
			exit(c3d_err_msg(EF_COLOR, 1));
		color->col[i] = col;
	}
	color->col[3] = 255;
	ft_freetab(coltab);
}

/**
 * checks if current line is valid then fills in texture or color
*/
static void	get_desc(char *str, t_prog *prog)
{
	if (!str || *str == '\n')
		return ;
	else if (ft_strnstr(str, "NO ", 3))
		load_texture(&(prog->textures.n), str + 3);
	else if (ft_strnstr(str, "SO ", 3))
		load_texture(&(prog->textures.s), str + 3);
	else if (ft_strnstr(str, "EA ", 3))
		load_texture(&(prog->textures.e), str + 3);
	else if (ft_strnstr(str, "WE ", 3))
		load_texture(&(prog->textures.w), str + 3);
	else if (ft_strnstr(str, "C ", 2))
		load_color(&(prog->c_color), str + 2);
	else if (ft_strnstr(str, "F ", 2))
		load_color(&(prog->f_color), str + 2);
	else
		exit(c3d_err_msg(EF_BADDESC, 1));
}

/**
 * runs trough list :
 * - If valid indentifier -> extraction
 * - If invalid indentifier -> stop + error
 * - if map or list ends -> stops
*/
void	c3d_get_infos(t_list **file, t_prog *prog)
{
	while (*file && !c3d_is_map_desc((*file)->content))
	{
		get_desc((*file)->content, prog);
		ft_lstdeltop(file, free);
	}
	prog->textures.d = mlx_load_png("textures/door.png");
	c3d_check_info(*prog);
	c3d_convert_colors(prog);
}
