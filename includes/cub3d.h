/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:29:24 by rficht            #+#    #+#             */
/*   Updated: 2023/08/02 16:43:51 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_HEIGHT 600
# define WIN_WIDTH 800

# define EF_ERR "Error\n"
# define EF_BADDESC "Error in file description\n"
# define EF_MISS "Missing data\n"
# define EF_WTEXTURE "Couldn't load texture\n"

# define MAP_SYMBOLES "01NSEW"

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "libgraph.h"

typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;
typedef struct s_vect2d			t_vect3d;

struct s_texture_pack
{
	mlx_texture_t	n;
	mlx_texture_t	s;
	mlx_texture_t	e;
	mlx_texture_t	w;
};

struct s_color
{
	char			*fullcolor;
	unsigned char	col[4];
};

struct s_prog
{
	int				err;
	int				height;
	int				width;
	char			**map;
	int				map_y;
	int				map_x;
	t_texture_pack	textures;
	t_color			f_color;
	t_color			c_color;
};

struct s_vect2d
{
	int	x;
	int	y;
};

int	cub3d_parsing(int argc, char *argv[], t_prog *prog);
int	get_infos(t_list **file_lst, t_prog *prog);
int	get_map(t_list **map_lst, t_prog *prog);
int	is_valid_ext(char *file, char *ext);
int	err_msg(char *msg, int err);
int	get_infos(t_list **file, t_prog *prog);
int	load_texture(mlx_texture_t *texture, char *file);
int	load_color(t_color *color, char *str);

#endif