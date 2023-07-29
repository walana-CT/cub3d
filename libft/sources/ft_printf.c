/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:39 by rficht            #+#    #+#             */
/*   Updated: 2022/12/10 11:22:06 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_read_str(const char **format, t_strlist **lst)
{
	unsigned int	n;
	char			*str;
	t_strlist		*new;
	const char		*format_copy;

	n = 0;
	format_copy = *format;
	while (format_copy[n] && format_copy[n] != '%')
		n++;
	str = ft_strndup(format_copy, n);
	if (!str)
		return (0);
	new = ft_strlst_new(str, n);
	if (!new)
	{
		free (str);
		return (0);
	}
	ft_strlst_addback(lst, new);
	*format = &format_copy[n];
	return (1);
}

int	ft_convert_percent(t_strlist **lst, va_list args, char c)
{
	if (c == 'c')
		return (ft_percent_c(lst, va_arg(args, int)));
	else if (c == 's')
		return (ft_percent_s(lst, va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_percent_i(lst, va_arg(args, int)));
	else if (c == 'u')
		return (ft_percent_u(lst, va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_percent_p(lst, va_arg(args, void *)));
	else if (c == 'x' || c == 'X')
		return (ft_percent_x(lst, va_arg(args, unsigned int), c == 'X'));
	else if (c == '%')
		return (ft_percent_c(lst, '%'));
	return (0);
}

int	ft_read_percent(const char **format, t_strlist **lst,
							va_list args)
{
	(*format)++;
	if (!ft_convert_percent(lst, args, **format))
		return (0);
	(*format)++;
	return (1);
}

int	ft_read_format(const char **format, t_strlist **lst, va_list args)
{
	int	error;

	if (**format == '%')
		error = ft_read_percent(format, lst, args);
	else
		error = ft_read_str(format, lst);
	return (error);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_strlist		**lst;
	char			*str;
	int				str_len;

	str_len = 1;
	lst = calloc(1, sizeof(t_strlist *));
	if (!lst)
		return (-1);
	va_start(args, format);
	while (*format && str_len)
		str_len = ft_read_format(&format, lst, args);
	if (!str_len)
		return (ft_strlst_clear(lst));
	str_len = ft_strlst_len(*lst);
	str = ft_strlst_merge(*lst, str_len);
	if (!str)
		return (ft_strlst_clear(lst));
	str_len = write(1, str, str_len);
	ft_strlst_clear(lst);
	va_end(args);
	free (str);
	return (str_len);
}
