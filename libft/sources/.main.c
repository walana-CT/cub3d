/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:07:30 by rficht            #+#    #+#             */
/*   Updated: 2022/12/12 15:47:05 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<string.h>
#include<stdio.h>

int	main(void)
{
	char *str;
	int fd;

	fd = open("basictest.fdf", O_RDONLY);
	if (fd == -1)
	{
		printf("fd = -1");
		return 0;
	}
	

	while ((str = ft_get_next_line(fd)))
	{
		printf("%s", str);
	}

	close(fd);
	return 0;
}


