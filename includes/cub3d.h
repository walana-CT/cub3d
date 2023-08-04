/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:29:24 by rficht            #+#    #+#             */
/*   Updated: 2023/08/04 13:26:18 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_HEIGHT 600
# define WIN_WIDTH 800

# define EF_ERR "Error\n"
# define EF_BADDESC "Bad file description\n"
# define EF_MISS "Missing data\n"
# define EF_WTEXTURE "Couldn't load texture\n"
# define EF_2TEXTURE "Texture already loaded\n"
# define EF_COLOR "Wrong color code. Format is 0~255,0~255,0~255\n"

# define MAP_SYMBOLES "01NSEW"

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "libgraph.h"

typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;
typedef struct s_vect2d			t_vect2d;

struct s_texture_pack
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
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
	mlx_t			*mlx;
	t_texture_pack	textures;
	t_color			f_color;
	t_color			c_color;
};

struct s_vect2d
{
	int	x;
	int	y;
};

// Parsing
int	cub3d_parsing(int argc, char *argv[], t_prog *prog);
int	get_infos(t_list **file_lst, t_prog *prog);
int	get_map(t_list **map_lst, t_prog *prog);
int	is_valid_ext(char *file, char *ext);
int	err_msg(char *msg, int err);
int	get_infos(t_list **file, t_prog *prog);
int	load_texture(mlx_texture_t **texture, char *file);
int	load_color(t_color *color, char *str);
int	is_map_desc(char *str);
int	check_info(t_prog prog);


#endif