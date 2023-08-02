/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:29:24 by rficht            #+#    #+#             */
/*   Updated: 2023/07/31 15:25:37 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define WIN_HEIGHT 600
# define WIN_WIDTH 800

# define EF_BADDESC "Error in file description\n"
# define EF_MISS "Missing data\n"

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "libgraph.h"

typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;

struct s_texture_pack
{
	char	*n;
	char	*s;
	char	*e;
	char	*o;
};

struct s_color
{
	char			*fullcolor;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

struct s_prog
{
	int				height;
	int				width;
	char			**map;
	t_texture_pack	textures;
	t_color			f_color;
	t_color			c_color;
};

int	cube3d_parsing(int argc, char *argv[], t_prog *prog);
int	get_infos(t_list **file_lst, t_prog *prog);

#endif