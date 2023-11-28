#include "cub3d.h"

void	ft_putlst(t_list **lst)
{
	t_list	*lst_read;

	if (!lst)
		exit(err_msg(EF_FAT, 1));
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
		exit(err_msg("Couldn't open file\n",1));
	str = ft_get_next_line(fd);
	while (str)
	{
		new_elem = ft_lstnew((void *)str);
		if (!new_elem)
			exit(err_msg(EF_FAT, 1));
		ft_lstadd_back(map_lst, new_elem);
		str = ft_get_next_line(fd);
	}
	if (close(fd))
		exit(err_msg("Couldn't close file\n",1));
}

void	c3d_parsing(int argc, char *argv[], t_prog *prog)
{
	t_list	**file_lst;

	(void) argc;
	file_lst = ft_calloc(1, sizeof(t_list *));
	if (!file_lst)
		exit(err_msg(EF_FAT, 1));
	ft_file_to_lst(*argv, file_lst);
	get_infos(file_lst, prog);
	c3d_get_map(file_lst, prog);
	ft_lstdel(file_lst, free);
}
