#include "cub3d.h"

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
	printf("Loaded texture file\t%s\n", file);
	return (0);
}

void	null_str_if_empty(char **str)
{
	ft_strshortenby(*str, 1);
	if (!ft_strcmp(*str, ""))
		*str = NULL;
}

int	load_color(t_color *color, char *str)
{
	char	**coltab;
	int		i;
	int		col;

	null_str_if_empty(&str);
	if (commascheck(str))
		exit(err_msg(EF_COLOR, 1));
	color->fullcolor = ft_strdup(str);
	coltab = ft_split(str, ',');
	if (!coltab)
		return (err_msg(EF_COLOR, 1));
	i = -1;
	while (++i < 3)
	{
		col = ft_atouc(coltab[i]);
		if (col == -1)
			return (ft_freetab(coltab), err_msg(EF_COLOR, 2));
		color->col[i] = col;
	}
	if (coltab[3])
		return (ft_freetab(coltab), 1);
	color->col[3] = 255;
	return (ft_freetab(coltab), 0);
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
	prog->textures.d = mlx_load_png("textures/door.png");
	return (check_info(*prog));
	if (!check_info(*prog))
		return (c3d_convert_colors(prog));
	else
		return (1);
}
