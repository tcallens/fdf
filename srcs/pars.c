/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:55:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/06 19:33:13 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*fill_coord_value(char *str, int y, int x, t_line *line)
{
	line->y = y;
	line->x = x;
	if (*str && *str == '0')
		line->height = 0;
	else if (*str && *str > '0' && *str <= '9')
		line->height = ft_atoi(&(*str));
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str && *str == ',')
	{
		if (*str && check_hex(&(*str)) < 7)
			line->color = ft_strdup(&(*str));
	}
	else
		line->color = ft_strdup("");
	return (line);
}

t_line		*fill_line(int y, char **split)
{
	t_line	*line;
	t_line	*tmp;
	t_line	*first;
	int		a;
	int		x;

	a = 0;
	x = 0;
	tmp = NULL;
	if ((line = (t_line *)malloc(sizeof(t_line))) == NULL)
		error_system();
	if (split[a])
		line = fill_coord_value(split[a++], y, x++, line);
	first = line;
	while (split[a])
	{
		if ((line->next = (t_line *)malloc(sizeof(t_line))) == NULL)
			error_system();
		line = line->next;
		line = fill_coord_value(split[a], y, x++, line);
		a++;
	}
	return (first);
}

t_fdf		*parsing(int fd, int y, t_fdf *fdf)
{
	t_line	**line;
	char	*n_line;
	char	**split;
	int		a;

	fdf->max_y = y;
	fdf->max_x = 0;
	a = 0;
	if ((line = (t_line **)malloc(sizeof(t_line *) * fdf->max_y)) == NULL)
		error_system();
	while (get_next_line(fd, &n_line) == 1 && a < fdf->max_y)
	{
		split = ft_strsplit(n_line, ' ');
		line[a] = fill_line(a, split);
		a++;
		free_tab(split);
		ft_memdel((void **)&n_line);
	}
	fdf->line = line;
	return (fdf);
}
