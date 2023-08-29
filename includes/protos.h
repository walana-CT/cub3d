/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:39:27 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/08/25 16:52:57 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H
# include "define.h"
# include "libft.h"

int			load_texture(mlx_texture_t **texture, char *file);
int			load_color(t_color *color, char *str);

// Utils
void		cub3d_init(t_prog *prog);
int			graph_init(t_prog *prog);
int			c3d_cub_free_map(char **map);
void		c3d_bool_flipflop(int *val);
int			c3d_create_map(t_list **file_lst, t_prog *prog);
void		c3d_final_free(t_prog *prog);
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
int			c3d_create_fov(t_prog *prog);
int			c3d_create_minimap(t_prog *prog);
int			c3d_create_player(t_prog *prog);
void		c3d_dispplayer(t_prog prog, t_player p);
void		c3d_draw_line(mlx_image_t *map_img, t_line line, uint32_t col);
void		c3d_drawsquare(t_prog prog, int x, int y, uint32_t col);
void		c3d_raycast(t_prog *prog);

// moving
//void		c3d_moveplayer(float dir_y, float dir_x, t_prog *prog);
int			is_pos_ok(float x, float y, t_prog *prog);
int			correct_pos(float x, float y, t_prog *prog);
int			c3d_moveplayer(float spd, t_prog *prog);
int			c3d_rotateplayer(int32_t mouse_x, t_prog *prog);

// hook
void		c3d_keyhook(mlx_key_data_t keydata, void *param);
void		c3d_mainhook(void *param);

// main funcs
int			c3d_refresh_image(t_prog *prog);
int			c3d_refresh_player(t_prog *prog);
int			c3d_refresh(t_prog *prog);

//minimap_centered
void		c3d_draw_minimap_centered(t_prog *prog);

//raycasting
void		c3d_raycasting(t_prog *prog);

#endif
