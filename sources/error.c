#include "cub3d.h"

int	c3d_err_msg(char *msg, int err)
{
	ft_putstr_fd(ERR, 2);
	ft_putstr_fd(msg, 2);
	return (err);
}

void	free_infos(t_prog *prog)
{
	if (prog->textures.e)
		mlx_delete_texture(prog->textures.e);
	if (prog->textures.w)
		mlx_delete_texture(prog->textures.w);
	if (prog->textures.n)
		mlx_delete_texture(prog->textures.n);
	if (prog->textures.s)
		mlx_delete_texture(prog->textures.s);
	free(prog->c_color.fullcolor);
	free(prog->f_color.fullcolor);
}

void	c3d_final_free(t_prog *prog)
{
	ft_freetab(prog->map);
	free_infos(prog);
}
