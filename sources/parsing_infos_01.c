#include "cub3d.h"

// Map description starts when a line begins with either '1' or ' ' char
int	is_map_desc(char *str)
{
	return (*str == '1' || *str == ' ');
}

int	commascheck(char *str)
{
	int	i;

	i = 0;
	while(*str)
		if (*str++ == ',')
			++i;
	return (!(i == 2));
}

int	color_ok(t_color color)
{
	if (ft_isuchar(color.col[0]) && ft_isuchar(color.col[1]) && \
		ft_isuchar(color.col[2]) && ft_isuchar(color.col[3]))
		return (1);
	return (0);
}

void	convert_colors(t_prog *prog)
{
	prog->c_color.color = (prog->c_color.col[0] << 16) | (prog->c_color.col[1] << 8) | prog->c_color.col[2];
	prog->c_color.color = (prog->f_color.col[0] << 16) | (prog->f_color.col[1] << 8) | prog->f_color.col[2];
    printf("La valeur C hexadécimale est : %d\n", prog->c_color.color);
    printf("La valeur F hexadécimale est : %d\n", prog->f_color.color);
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
	convert_colors(&prog);
	return (0);
}
