/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rficht <robin.ficht@free.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:26:42 by rficht            #+#    #+#             */
/*   Updated: 2022/12/12 15:46:23 by rficht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include"libft.h"

char	*ft_ejector_seat(char **tab);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef TAB_SIZE
#  define TAB_SIZE 512
# endif

#endif
