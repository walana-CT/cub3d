#include "cub3d.h"

// Map description starts when a line begins with either '1' or ' ' char
int	c3d_is_map_desc(char *str)
{
	return (*str == '1' || *str == ' ');
}

void	c3d_commascheck(char *str)
{
	int	i;

	i = 0;
	while (*str)
		if (*str++ == ',')
			++i;
	if (i != 2)
		exit(c3d_err_msg(EF_COLOR, 1));
}

void	check_color(t_color color)
{
	if (ft_isuchar(color.col[0]) && ft_isuchar(color.col[1]) && \
		ft_isuchar(color.col[2]) && ft_isuchar(color.col[3]))
		return ;
	exit(c3d_err_msg(EF_COLOR, 1));
}

void	c3d_convert_colors(t_prog *prog)
{
	prog->c_color.color = (prog->c_color.col[0] << 24)
		| (prog->c_color.col[1] << 16) | (prog->c_color.col[2] << 8) | 255;
	prog->f_color.color = (prog->f_color.col[0] << 24)
		| (prog->f_color.col[1] << 16) | (prog->f_color.col[2] << 8) | 255;
}

/**
 * checks if all the needed infos are present (textures + colors)
 * try to open textures to see if they are valid
 * try to load textures with mlx ?
 * 
*/
void	c3d_check_info(t_prog prog)
{
	check_color(prog.c_color);
	check_color(prog.f_color);
	if (!prog.textures.n || !prog.textures.s || \
		!prog.textures.e ||!prog.textures.w)
		exit(c3d_err_msg(EF_MISS, 2));
}
