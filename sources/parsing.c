/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:28:09 by rficht            #+#    #+#             */
/*   Updated: 2023/08/02 11:32:11 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



/**
 * run trough list :
 * - If valid indentifier -> extraction
 * - If invalid indentifier -> stop + error
 * - if map or list ends -> stops
*/
/*int	extract_infos(t_list **map_lst, t_prog *t_prog)
{
	return (0);
}*/


/**
 * check if all the needed infos are present (textures + colors)
 * try to open textures to see if theu are valid
 * 
*/
/*int	check_info(t_prog *prog)
{
	return(0);
}*/


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
/*int	check_map(t_prog *prog)
{
	return(0);
}*/

void	ft_putlst(t_list **lst)
{
	t_list	*lst_read;

	if (!lst)
	{
		printf("lst does not exist\n");
		return ;
	}
	lst_read = *lst;
	while (lst_read)
	{
		printf("%s", lst_read->content);
		lst_read = lst_read->next;
	}	
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

int	cub3d_parsing(int argc, char *argv[], t_prog *prog)
{
	t_list	**file_lst;

	printf("%d , %s\n", argc, *argv);
	file_lst = ft_calloc(1, sizeof(t_list *));
	if (!file_lst)
		return (1);
	if (ft_file_to_lst(*argv, file_lst))
	{
		ft_lstdel(file_lst, free);
		return (perror("cub2d: ft_file_to_lst: "), 1);
	}
	ft_putlst(file_lst);
	//int extract_infos(map_lst, prog);
	if (get_map(file_lst, prog))
	{
		ft_lstdel(file_lst, free);
		return (1);
	}
	return (0);
}




