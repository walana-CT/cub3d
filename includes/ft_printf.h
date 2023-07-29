/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:24:22 by rficht            #+#    #+#             */
/*   Updated: 2023/07/27 17:22:13 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>
# include"libft.h"

//percent converting functions
int			ft_percent_c(t_strlist **lst, char c);
int			ft_percent_s(t_strlist **lst, char *c);
int			ft_percent_i(t_strlist **lst, int i);
int			ft_percent_u(t_strlist **lst, unsigned int u);
int			ft_percent_p(t_strlist **lst, void *ptr);
int			ft_percent_x(t_strlist **lst, unsigned int u, int up);

# ifndef HEX_BASE
#  define HEX_BASE "0123456789abcdef"
# endif

# ifndef HEX_BASE_UP
#  define HEX_BASE_UP "0123456789ABCDEF"
# endif

#endif
