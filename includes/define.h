/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:37:40 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/25 17:16:18 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H

# include "MLX42.h"
# define DEFINE_H
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define SPD 0.05
# define SENSIVITY 0.01
# define WALL 0x888888FF
# define VOID 0xDDDDDDFF
# define WALK 0xBBBBBBFF
# define PLAYER 0xF455EAFF

# define ERR "Error\n"
# define EF_BADDESC "Bad file description\n"
# define EF_MISS "Missing data\n"
# define EF_WTEXTURE "Couldn't load texture\n"
# define EF_2TEXTURE "Texture already loaded\n"
# define EF_COLOR "Wrong color code. Format is [0-255],[0-255],[0-255]\n"
# define EF_WMAP "Map not valid\n"
# define EF_MOPEN "Map not closed\n"

# define MAP_SYMBOLS "01NSEW"
# define MAP_WALKABLE_SYMBOL "0NSEW"

typedef struct s_player			t_player;
typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;
typedef struct s_vect2d			t_vect2d;
typedef struct s_line			t_line;
typedef struct s_ray			t_ray;
typedef struct s_size			t_size;

struct s_size
{
	int		minimap_height;
	int		minimap_width;
	int		mapscale;
	float	pl_scale;
	float	pl_hb;
};

struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	dx;
	int	dy;
	int	incx;
	int	incy;
	int	err;
	int	e2;
};

struct s_ray
{
	float	dir;
	float	ax;
	float	ay;
	float	bx;
	float	by;
};

struct s_vect2d
{
	int	x;
	int	y;
};

struct s_player
{
	float	x;
	float	y;
	float	hb;
	float	size;
	int		size_int;
	float	dir;
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
	int				w_height;	// window_height
	int				w_width;	// window_width
	char			**map;
	int				map_height;		// max ?
	int				map_width;		// max ?
	int32_t			mouse_x;
	t_vect2d		center;
	mlx_t			*mlx;
	mlx_image_t		*minimap_img;
	mlx_image_t		*fov_img;
	mlx_image_t		*player_img;
	t_size			size;
	t_texture_pack	textures;
	t_color			f_color;
	t_color			c_color;
	t_player		player;
};

#endif