/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <rficht@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:28:09 by rficht            #+#    #+#             */
/*   Updated: 2023/11/09 15:37:02 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		printf("%s", (char *) lst_read->content);
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

int	c3d_parsing(int argc, char *argv[], t_prog *prog)
{
	t_list	**file_lst;

	(void) argc;
	file_lst = ft_calloc(1, sizeof(t_list *));
	if (!file_lst)
		return (1);
	if (ft_file_to_lst(*argv, file_lst))
	{
		ft_lstdel(file_lst, free);
		return (perror("cub3d: ft_file_to_lst: "), 1);
	}
	if (get_infos(file_lst, prog) || c3d_get_map(file_lst, prog))
		return (ft_lstdel(file_lst, free), 1);
	return (ft_lstdel(file_lst, free), 0);
}
