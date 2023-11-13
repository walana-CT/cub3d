/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamat <mamat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:15:34 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/11/13 14:35:47 by mamat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define SPD 0.05
# define SENSIVITY 0.01
# define WALL 0x888888FF
# define VOID 0xDDDDDDFF
# define WALK 0xBBBBBBFF
# define DOOR 0xFF0000FF
# define OP_DOOR 0x00FF00FF
# define PLAYER 0xF455EAFF
# define FOV 90


# define SKY 0x526FD2FF
# define GROUND 0xC8b4A4FF
# define NORTH_C 0xFB9902FF
# define SOUTH_C 0x347C98FF
# define EAST_C 0xC21460FF
# define WEST_C 0xFCCC1AFF

# define ERR "Error\n"
# define EF_BADDESC "Bad file description\n"
# define EF_MISS "Missing data\n"
# define EF_WTEXTURE "Couldn't load texture\n"
# define EF_2TEXTURE "Texture already loaded\n"
# define EF_COLOR "Wrong color code. Format is [0-255],[0-255],[0-255]\n"
# define EF_WMAP "Map not valid\n"
# define EF_MOPEN "Map not closed\n"

# define MAP_SYMBOLS "01NSEWCO" // C = door, O = open door
# define MAP_WALKABLE_SYMBOL "0NSEWO"

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
typedef struct s_coord			t_coord;
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

struct s_coord
{
	int	x;
	int	y;
};

struct s_vect2d
{
	float	x;
	float	y;
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
	int				disp_minimap;	// bool
	int32_t			mouse_x;
	t_coord			center;
	mlx_t			*mlx;
	mlx_image_t		*minimap_img;
	mlx_image_t		*fov_img;
	mlx_image_t		*player_img;
	mlx_image_t		*view_img;
	t_texture_pack	textures;
	t_color			f_color;
	t_color			c_color;
	t_player		player;
	t_size			size;
};

struct s_ray
{
	t_vect2d	start;
	t_vect2d	d_step;
	t_vect2d	intersection;
	t_vect2d	lenght;
	t_coord		map_check;
	t_coord		step;
	float		distance;
	float		dx;
	float		dy;
	int			has_collide;
};

// Utils
int			c3d_cub_free_map(char **map);
void		c3d_bool_flipflop(int *val);
int			c3d_create_map(t_list **file_lst, t_prog *prog);
char		**c3d_map_dup(t_prog *prog);
int			err_msg(char *msg, int err);

// Parsing
int			c3d_parsing(int argc, char *argv[], t_prog *prog);
int			get_infos(t_list **file_lst, t_prog *prog);
int			c3d_get_map(t_list **map_lst, t_prog *prog);
void		c3d_clean_map(char **map, t_prog *prog);
int			is_valid_ext(char *file, char *ext);
int			load_texture(mlx_texture_t **texture, char *file);
int			load_color(t_color *color, char *str);
int			is_map_desc(char *str);
int			c3d_is_map_closed(t_prog *prog);
int			check_info(t_prog prog);

// drawing
t_line		c3d_create_line(int a, int b, int c, int d);
int			c3d_create_fov(t_prog *prog);
int			c3d_create_minimap(t_prog *prog);
int			c3d_create_player(t_prog *prog);
void		c3d_dispplayer(t_prog prog, t_player p);
void		c3d_draw_line(mlx_image_t *map_img, t_line line, uint32_t col);
void		c3d_drawsquare(t_prog prog, int x, int y, uint32_t col);
void		c3d_raycast(t_prog *prog);

// moving
char		c3d_get_front_tile(t_prog *prog);
void		c3d_door_interact(t_prog *prog);
int			c3d_moveplayer(float spd, t_prog *prog);
char		c3d_player_facing(float dir);
int			c3d_strafeplayer(float spd, t_prog *prog);
int			correct_pos(float x, float y, t_prog *prog);
int			c3d_rotateplayer(int32_t mouse_x, t_prog *prog);

// hook
void		c3d_keyhook(mlx_key_data_t keydata, void *param);
void		c3d_mainhook(void *param);
void 		c3d_mousehook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);


// main funcs
int			c3d_refresh_image(t_prog *prog);
int			c3d_refresh_player(t_prog *prog);
int			c3d_refresh(t_prog *prog);
int			c3d_refresh_fov(t_prog *prog);

//minimap_centered
void		c3d_draw_minimap_centered(t_prog *prog);

//raycasting
void		c3d_cast_one(t_prog *prog, float dir, int x_pos);

// Utils
void		cub3d_init(t_prog *prog);
int			graph_init(t_prog *prog);
void		c3d_final_free(t_prog *prog);
t_coord		c3d_get_player_pos(char **map);

#endif