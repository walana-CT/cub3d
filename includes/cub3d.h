/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:15:34 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/15 13:33:56 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MINIMAP_Y 800
# define MINIMAP_X 800
# define SCALE 16
# define PLAYER_SCALE 0.25
# define SPD 0.05
# define TSPD 0.1
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

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"
# include "math.h"
# include "libgraph.h"

typedef struct s_player			t_player;
typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;
typedef struct s_vect2d			t_vect2d;
typedef struct s_line			t_line;

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
	int				w_height;
	int				w_width;
	char			**map;
	int				map_y; // max ?
	int				map_x; // max ?
	t_vect2d		center;
	mlx_t			*mlx;
	mlx_image_t		*minimap_img;
	mlx_image_t		*player_img;
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

// drawing
t_line		c3d_create_line(int a, int b, int c, int d);
void		c3d_create_minimap(t_prog *prog);
int			c3d_create_player(t_prog *prog);
void		c3d_dispplayer(t_prog prog, t_player p);
void		c3d_draw_line(mlx_image_t *map_img, t_line line, uint32_t col);
void		c3d_drawsquare(t_prog prog, int x, int y, uint32_t col);

// moving
//void		c3d_moveplayer(float dir_y, float dir_x, t_prog *prog);
void		c3d_moveplayer(float spd, t_prog *prog);
void		c3d_rotateplayer(float inc, t_prog *prog);

// hook
void		c3d_keyhook(mlx_key_data_t keydata, void *param);
void		c3d_mainhook(void *param);

// main funcs
int			c3d_refresh_image(t_prog *prog);
int			c3d_refresh_player(t_prog *prog);

//minimap_centered
void		c3d_draw_minimap_centered(t_prog *prog);

#endif