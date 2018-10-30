/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:07:07 by tcallens          #+#    #+#             */
/*   Updated: 2018/03/26 20:04:57 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_listt		*ft_manage(t_listt **list, int fd)
{
	t_listt *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!tmp)
	{
		if (!(tmp = malloc(sizeof(t_listt))))
			return (NULL);
		tmp->content = ft_strdup("");
		tmp->fd = fd;
		tmp->next = *list;
		*list = tmp;
	}
	return (tmp);
}

static char			*ft_read_fd(const int fd, char *str)
{
	char	*buff;
	char	*tmp;
	int		ver;

	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	while ((ver = read(fd, buff, BUFF_SIZE)))
	{
		if (ver == -1)
		{
			ft_strdel(&buff);
			return (NULL);
		}
		buff[ver] = '\0';
		if (!(tmp = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&str);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	ft_strdel(&buff);
	return (str);
}

static int			ft_range(char **line, char **content, char **tmp)
{
	if (!(*tmp = ft_strdup(*content)))
		return (-1);
	ft_strdel(content);
	if (**tmp == '\n')
	{
		if (!(*content = ft_strdup(*tmp + 1)))
			return (-1);
		ft_strdel(tmp);
		if (!(*line = ft_strnew(0)))
			return (-1);
		return (1);
	}
	if (!(*content = ft_strchr(*tmp, '\n') ?
				ft_strdup(ft_strchr(*tmp, '\n') + 1) :
				ft_strnew(0)))
		return (-1);
	if ((ft_strchr(*tmp, '\n')))
		*(ft_strchr(*tmp, '\n')) = '\0';
	*line = *tmp;
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_listt		*tl = NULL;
	t_listt				*use;
	int					ver;
	char				*tmp;

	if (fd < 0 || !line)
		return (-1);
	if (!(use = ft_manage(&tl, fd)))
		return (-1);
	if (!(ft_strchr(use->content, '\n')))
	{
		if (!(use->content = ft_read_fd(fd, use->content)))
			return (-1);
	}
	ver = ft_range(line, &use->content, &tmp);
	return (ver == 0 ? !!**line : ver);
}
