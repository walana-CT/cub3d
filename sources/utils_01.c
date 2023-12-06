/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:45:31 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/06 12:45:32 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_toggle_minimap(t_prog *prog)
{
	prog->disp_minimap = ((prog->disp_minimap + 1) % 2);
	prog->minimap_img->enabled = prog->disp_minimap;
	prog->fov_img->enabled = prog->disp_minimap;
}

void	c3d_toggle_run(t_prog *prog)
{
	if (prog->run == 4)
		prog->run = 1;
	else
		prog->run *= 2;
}

void	c3d_toggle_help(t_prog *prog)
{
	mlx_texture_t	*help_text;

	if (!prog->help_img)
	{
		help_text = mlx_load_png("textures/help.png");
		if (!help_text)
			exit(c3d_err_msg(EF_FAT, 1));
		prog->help_img = mlx_texture_to_image(prog->mlx, help_text);
		if (!prog->help_img)
			exit(c3d_err_msg(EF_FAT, 1));
		mlx_delete_texture(help_text);
		if (mlx_image_to_window(prog->mlx, prog->help_img,
				(prog->w_width - prog->help_img->width) / 2,
				(prog->w_height - prog->help_img->height) / 2) == -1)
			exit(c3d_err_msg(EF_FAT, 1));
		mlx_set_instance_depth(prog->help_img->instances, 5);
	}
	else if (prog->help_img->enabled)
		prog->help_img->enabled = 0;
	else
		prog->help_img->enabled = 1;
}
