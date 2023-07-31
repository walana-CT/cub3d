/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:28:09 by rficht            #+#    #+#             */
/*   Updated: 2023/07/31 10:08:55 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



/**
 * run trough list :
 * - If valid indentifier -> extraction
 * - If invalid indentifier -> stop + error
 * - if map or list ends -> stops
*/
int	extract_infos(t_list **map_lst, t_prog *t_prog)
{
	return (0);
}


/**
 * check if all the needed infos are present (textures + colors)
 * try to open textures to see if theu are valid
 * 
*/
int	check_info(t_prog *prog)
{
	return(0);
}


/**
 * verify if the map size is ok (not too big)
 * turn spaces into '0'
 * adds '\0' so it is safer to explore :
 * 
 * 
 *    111o
 *    101o
 * 111101o
 * 10000111o
 * 10000001o
 * 11111111o
 * NULL
 * 
 * will become
 * 
 * 000111ooo
 * 000101ooo
 * 111101ooo
 * 10000111o
 * 10000001o
 * 11111111o
 * ooooooooo
 * NULL
 * 
 * verify if the map is valid (1 player that cant go out)
 * 
*/
int	check_map(t_prog *prog)
{
	return(0);
}


void	ft_putlst(t_list **lst)
{
	t_list	*lst_read;

	if (!lst)
	{
		printf("lst is does not exist\n");
		return ;
	}
	lst_read = *lst;
	while (lst_read)
	{
		printf("%s\n", lst_read->content);
		lst_read = lst_read->next;
	}	
}

int	invalid_name(char *arg)
{
	int	n;

	n = -1;
	while (arg[++n])
	{
		if (arg[n] == '.' && arg[n + 1] == 'c'
			&& arg[n + 2] == 'b' && arg[n + 3] == 'b'
			&& !arg[n + 4])
			return (TRUE);
	}
	return (FALSE);
}

static int	ft_file_to_lst(char *file, t_list **map_lst)
{
	char		*str;
	t_list		*new_elem;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	str = ft_get_next_line(fd);
	while (str)
	{
		new_elem = ft_lstnew((void *)str);
		if (!new_elem)
			return (1);
		ft_lstadd_back(map_lst, new_elem);
		str = ft_get_next_line(fd);
	}
	if (close(fd))
		return (1);
	return (0);
}

int	cube2d_parsing(int argc, char *argv[], t_prog *prog)
{
	t_list	**map_lst;
	(void)	prog;

	printf("%d , %s\n", argc, *argv);
	if (argc != 1)
	{
		printf("cub2d require 1 argument (map path)\n");
		return (1);
	}

	if (invalid_name(*argv))
	{
		printf("invalid file name (must end by .cub)\n");
		return (1);
	}

	map_lst = ft_calloc(1, sizeof(t_list *));
	if (!map_lst)
		return (1);

	if (ft_file_to_lst(*argv, map_lst))
	{
		ft_lstclear(map_lst, free);
		perror("cub2d: ft_file_to_lst: ");
		return (1);
	}
	ft_putlst(map_lst);
	//int extract_infos(map_lst, prog);



	if (extract_map(map_lst, prog))
	{
		ft_lstclear(map_lst, free);
		return (1);
	}
	check_info(prog);
	check_map(prog);
	return (0);
}

/**
 * extract map line of list and put them in char array
 * if invalide char -> stop + error
 * if empty line or list end -> stop
 * free list.
 * if no map return error
 */
static int	**extract_map(t_list **map_lst, t_prog *prog)
{
	return (0);
}


