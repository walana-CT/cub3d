/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:15:34 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/08 11:48:11 by rficht           ###   ########.fr       */
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
# define EF_COLOR "Wrong color code. Format is [0-255],[0-255],[0-255]\n"

# define MAP_SYMBOLS "01NSEW"

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "libgraph.h"

typedef struct s_player			t_player;
typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;
typedef struct s_vect2d			t_vect2d;

struct s_vect2d
{
	int	x;
	int	y;
};

struct s_player
{
	t_vect2d	pos;
	float		direction;
};

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
	t_player		player;
};

int			load_texture(mlx_texture_t **texture, char *file);
int			load_color(t_color *color, char *str);

// Utils
int			c3d_cub_free_map(char **map);
void		c3d_bool_flipflop(int *val);
int			c3d_create_map(t_list **file_lst, t_prog *prog);
char		**c3d_map_dup(t_prog *prog);
t_vect2d	c3d_get_player_pos(char **map);
int			is_valid_ext(char *file, char *ext);
int			err_msg(char *msg, int err);

// Parsing
int			c3d_parsing(int argc, char *argv[], t_prog *prog);
int			get_infos(t_list **file_lst, t_prog *prog);
int			c3d_get_map(t_list **map_lst, t_prog *prog);
void		c3d_clean_map(char **map, t_prog *prog);
int			is_valid_ext(char *file, char *ext);
int			err_msg(char *msg, int err);
int			get_infos(t_list **file, t_prog *prog);
int			load_texture(mlx_texture_t **texture, char *file);
int			load_color(t_color *color, char *str);
int			is_map_desc(char *str);
int			c3d_is_map_closed(t_prog *prog);
int			check_info(t_prog prog);

#endif