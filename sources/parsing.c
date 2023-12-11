/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdjemaa <mdjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:45:20 by mdjemaa           #+#    #+#             */
/*   Updated: 2023/12/11 14:27:21 by mdjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putlst(t_list **lst)
{
	t_list	*lst_read;

	if (!lst)
		exit(c3d_err_msg(EF_FAT, 1));
	lst_read = *lst;
	while (lst_read)
	{
		printf("%s", (char *) lst_read->content);
		lst_read = lst_read->next;
	}	
}

static void	ft_file_to_lst(char *file, t_list **map_lst)
{
	char		*str;
	t_list		*new_elem;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(c3d_err_msg("Couldn't open file", 1));
	str = ft_get_next_line(fd);
	while (str)
	{
		new_elem = ft_lstnew((void *)str);
		if (!new_elem)
			exit(c3d_err_msg(EF_FAT, 1));
		ft_lstadd_back(map_lst, new_elem);
		str = ft_get_next_line(fd);
	}
	if (close(fd))
		exit(c3d_err_msg("Couldn't close file", 1));
}

void	c3d_parsing(int argc, char *argv[], t_prog *prog)
{
	t_list	**file_lst;

	(void) argc;
	file_lst = ft_calloc(1, sizeof(t_list *));
	if (!file_lst)
		exit(c3d_err_msg(EF_FAT, 1));
	ft_file_to_lst(*argv, file_lst);
	c3d_get_infos(file_lst, prog);
	c3d_get_map(file_lst, prog);
	ft_lstdel(file_lst, free);
}
