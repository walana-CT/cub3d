/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:29:24 by rficht            #+#    #+#             */
/*   Updated: 2023/08/01 15:06:43 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WIN_HEIGHT 600
# define WIN_WIDTH 800

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "libgraph.h"

typedef struct s_texture_pack	t_texture_pack;
typedef struct s_prog			t_prog;

# define MAP_SYMBOLES "01NSEO"

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

//parsing
int	cub3d_parsing(int argc, char *argv[], t_prog *prog);
int	get_map(t_list **map_lst, t_prog *prog);

#endif