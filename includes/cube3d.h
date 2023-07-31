/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:29:24 by rficht            #+#    #+#             */
/*   Updated: 2023/07/30 17:15:29 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_texture_pack	t_texture_pack;
typedef struct s_prog			t_prog;

struct s_texture_pack
{
	char	*n;
	char	*s;
	char	*e;
	char	*o;
};


struct s_prog
{
	int				height;
	int				width;
	char			**map;
	t_texture_pack	textures;
	t_color			ground_color;
	t_color			sky_color;
};

int	cube2d_parsing(int argc, char *argv[], t_prog *prog);

#endif