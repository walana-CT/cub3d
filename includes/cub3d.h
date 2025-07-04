/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:37:08 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/08 13:23:35 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define SPD 0.025
# define SENSIVITY 0.01
# define WALL 0x888888FF
# define VOID 0xDDDDDDFF
# define WALK 0xBBBBBBFF
# define DOOR 0xFF0000FF
# define OP_DOOR 0x00FF00FF
# define FOV 102
# define DOG_RATIO_X 0.35
# define DOG_RATIO_Y 0.35
# define VERT 0x3568A688

# define ERR "Error\n"
# define EF_FAT "Fatal error"
# define EF_BADDESC "Bad file description"
# define EF_MISS "Missing data"
# define EF_UNEX "Unexpected data"
# define EF_WTEXTURE "Couldn't load texture"
# define EF_2TEXTURE "Texture already loaded"
# define EF_COLOR "Wrong color code. Format is [0-255],[0-255],[0-255]"
# define EF_WMAP "Map not valid"
# define EF_MOPEN "Map not closed"

# define MAP_SYMBOLS "01NSEWCO" // C = door, O = open door
# define MAP_WALKABLE_SYMBOL "0NSEWO"

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "MLX42.h"
# include "math.h"

typedef struct s_player			t_player;
typedef struct s_prog			t_prog;
typedef struct s_color			t_color;
typedef struct s_texture_pack	t_texture_pack;
typedef struct s_coord			t_coord;
typedef struct s_vect2d			t_vect2d;
typedef struct s_line			t_line;
typedef struct s_ray			t_ray;
typedef struct s_size			t_size;
typedef struct s_dog			t_dog;

struct s_size
{
	int		minimap_height;
	int		minimap_width;
	int		mapscale;
	float	pl_scale;
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
	int		size_int;
	float	dir;
};

struct s_texture_pack
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;
	mlx_texture_t	*d;
};

struct s_color
{
	char			*fullcolor;
	unsigned char	col[4];
	uint32_t		color;
};

struct s_dog
{
	mlx_texture_t	*textures[14];
	int				size_x;
	int				size_y;
	int				pos_x;
	int				pos_y;
	mlx_image_t		*image;
};

struct s_prog
{
	int				err;
	int				w_height;
	int				w_width;
	char			**map;
	int				map_height;
	int				map_width;
	int				disp_minimap;
	int				run;
	int				is_moving;
	double			last_time;
	float			fov;
	int				mouse_ctrl;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int32_t			new_mouse_x;
	t_coord			center;
	mlx_t			*mlx;
	mlx_image_t		*minimap_img;
	mlx_image_t		*fov_img;
	mlx_image_t		*view_img;
	mlx_image_t		*help_img;
	t_texture_pack	textures;
	t_color			f_color;
	t_color			c_color;
	t_player		player;
	t_size			size;
	t_dog			dog;
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
	float		screen_dist;
	float		dx;
	float		dy;
	float		texture_x;
	float		texture_y;
	float		wall_x;
	int			has_collide;
	int			side;
	int			is_door;
};

// Utils
void		c3d_cub_free_map(char **map);
void		c3d_create_map(t_list **file_lst, t_prog *prog);
char		**c3d_map_dup(t_prog *prog);
int			c3d_err_msg(char *msg, int err);
void		c3d_init(t_prog *prog);
void		c3d_graph_init(t_prog *prog);
void		c3d_final_free(t_prog *prog);
t_coord		c3d_get_player_pos(char **map);
void		c3d_toggle_minimap(t_prog *prog);
void		c3d_toggle_run(t_prog *prog);
void		c3d_toggle_help(t_prog *prog);

// Parsing
void		c3d_commascheck(char *str);
void		c3d_convert_colors(t_prog *prog);
void		c3d_parsing(int argc, char *argv[], t_prog *prog);
void		c3d_get_infos(t_list **file_lst, t_prog *prog);
void		c3d_get_map(t_list **map_lst, t_prog *prog);
void		c3d_clean_map(char **map, t_prog *prog);
int			c3d_is_map_desc(char *str);
int			c3d_is_map_closed(t_prog *prog);
void		c3d_check_info(t_prog prog);
void		c3d_set_player_dir(char c, t_prog *prog);

// drawing
void		c3d_binoculars(t_prog *prog);
void		c3d_binoculars_anim(t_prog *prog);
void		c3d_casting(t_ray *ray, t_prog *prog, float r_dir);
t_line		c3d_create_line(int a, int b, int c, int d);
void		c3d_create_minimap(t_prog *prog);
void		c3d_dispplayer(t_prog prog, t_player p);
void		c3d_draw_line(mlx_image_t *map_img, t_line line, uint32_t col);
void		c3d_raycast(t_prog *prog);
void		c3d_refresh_fov(t_prog *prog);
void		c3d_refresh_view(t_prog *prog);
void		c3d_refresh(t_prog *prog);
void		c3d_refresh_fov(t_prog *prog);
uint32_t	c3d_get_pixel_color(mlx_texture_t *texture, float c_x, float c_y);

// moving
char		c3d_get_front_tile(t_prog *prog);
void		c3d_door_interact(t_prog *prog);
int			c3d_moveplayer(float spd, t_prog *prog);
char		c3d_player_facing(float dir);
int			c3d_strafeplayer(float spd, t_prog *prog);
int			c3d_correct_pos(float x, float y, t_prog *prog);
int			c3d_rotateplayer(float spd, t_prog *prog);
int			c3d_mouse_rotate(int32_t mouse_x, t_prog *prog);

// hook
void		c3d_keyhook(mlx_key_data_t keydata, void *param);
void		c3d_mainhook(void *param);
void		c3d_mousehook(mouse_key_t button, action_t action,
				modifier_key_t mods, void *param);
void		c3d_scrollhook(double xdelta, double ydelta, void *param);

//dog
void		c3d_dog_init(t_prog *prog);
void		c3d_dog_anim(t_prog *prog);
void		c3d_draw_dog(t_prog *prog, int n);
void		c3d_draw_img(t_prog *prog, int n);

#endif