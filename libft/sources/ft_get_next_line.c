/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:01:26 by rficht            #+#    #+#             */
/*   Updated: 2022/12/04 13:55:19 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_get_next_line.h"

static char	*ft_copy_cat(char *str, char *buffer, size_t buffer_len)
{
	char			*copy;
	char			*copy_copy;
	unsigned int	n;

	n = 0;
	copy = malloc((ft_strlen(str) + buffer_len + 1) * sizeof(char));
	if (!copy)
		return (ft_ejector_seat(&str));
	copy_copy = copy;
	if (str)
	{
		while (str[n])
			*copy++ = str[n++];
	}
	while (buffer_len--)
		*copy++ = *buffer++;
	*copy = '\0';
	if (str)
		free(str);
	str = 0;
	copy = copy_copy;
	return (copy);
}

static int	ft_line_found(char *str, size_t buffer_len)
{
	if (!buffer_len)
		return (1);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str++ == '\n')
			return (1);
	}
	return (0);
}

static char	*ft_trunc(char *str)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	if (!i)
		return (ft_ejector_seat(&str));
	result = malloc ((ft_strlen(str) - i + 1) * sizeof(char));
	if (!result)
		return (ft_ejector_seat(&str));
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	str = 0;
	return (result);
}

static char	*ft_grab_line(char *str)
{
	unsigned int	n;
	char			*result;

	if (!str)
		return (0);
	n = 0;
	while (str[n] != '\n' && str[n])
		n++;
	if (str[n] == '\n')
		n++;
	if (!n)
		return (0);
	result = malloc((n + 1) * sizeof(char));
	if (!result)
		return (0);
	result[n] = '\0';
	while (n--)
		result[n] = str[n];
	return (result);
}

char	*ft_get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	int				buffer_len;
	static char		*str[TAB_SIZE];
	char			*result;

	if (fd == -1)
		return (ft_ejector_seat(&str[fd]));
	buffer_len = 1;
	if (!str[fd])
		str[fd] = 0;
	while (!ft_line_found(str[fd], buffer_len))
	{
		buffer_len = read(fd, buffer, BUFFER_SIZE);
		if (buffer_len == -1)
			return (ft_ejector_seat(&str[fd]));
		str[fd] = ft_copy_cat(str[fd], buffer, buffer_len);
		if (!str[fd])
			return (0);
	}
	result = ft_grab_line(str[fd]);
	if (!result)
		return (ft_ejector_seat(&str[fd]));
	str[fd] = ft_trunc(str[fd]);
	return (result);
}
