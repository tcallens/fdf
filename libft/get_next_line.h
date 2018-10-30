/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:29:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/22 17:23:03 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 4096

typedef struct		s_listt
{
	int				fd;
	char			*content;
	struct s_listt	*next;
}					t_listt;

int					get_next_line(const int	fd, char **line);

#endif
