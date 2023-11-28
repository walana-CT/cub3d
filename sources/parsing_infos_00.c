#include "cub3d.h"

/**
 * checks if current line is valid then fills in texture or color
*/
void	get_desc(char *str, t_prog *prog)
{
	if (!str || *str == '\n')
		return;
	if (ft_strnstr(str, "NO ", 3))
		load_texture(&(prog->textures.n), str + 3);
	if (ft_strnstr(str, "SO ", 3))
		load_texture(&(prog->textures.s), str + 3);
	if (ft_strnstr(str, "EA ", 3))
		load_texture(&(prog->textures.e), str + 3);
	if (ft_strnstr(str, "WE ", 3))
		load_texture(&(prog->textures.w), str + 3);
	if (ft_strnstr(str, "C ", 2))
		load_color(&(prog->c_color), str + 2);
	if (ft_strnstr(str, "F ", 2))
		load_color(&(prog->f_color), str + 2);
}

void	load_texture(mlx_texture_t **texture, char *file)
{
	ft_strshortenby(file, 1);
	if (*texture)
		exit(err_msg(EF_2TEXTURE, 1));
	*texture = mlx_load_png(file);
	if (!*texture)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(err_msg(EF_WTEXTURE, 1));
	}
	printf("Loaded texture file\t%s\n", file);
}

void	null_str_if_empty(char **str)
{
	ft_strshortenby(*str, 1);
	if (!ft_strcmp(*str, ""))
		*str = NULL;
}

void	load_color(t_color *color, char *str)
{
	char	**coltab;
	int		i;
	int		col;

	null_str_if_empty(&str);
	if (color->fullcolor)
		exit(err_msg(EF_BADDESC, 1));	
	commascheck(str);
	color->fullcolor = ft_strdup(str);
	coltab = ft_split(str, ',');
	if (!coltab)
		exit(err_msg(EF_COLOR, 1));
	i = -1;
	while (++i < 3)
	{
		col = ft_atouc(coltab[i]);
		if (col == -1)
			exit(err_msg(EF_COLOR, 1));
		color->col[i] = col;
	}
	color->col[3] = 255;
	ft_freetab(coltab);
	ft_printf("Loaded color \t%s\n", color->fullcolor);
}

/**
 * runs trough list :
 * - If valid indentifier -> extraction
 * - If invalid indentifier -> stop + error
 * - if map or list ends -> stops
*/
void	get_infos(t_list **file, t_prog *prog)
{
	while (*file && !is_map_desc((*file)->content))
	{
		get_desc((*file)->content, prog);
		ft_lstdeltop(file, free);
	}
	check_info(*prog);
	c3d_convert_colors(prog);
}
