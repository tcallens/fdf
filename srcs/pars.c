/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:55:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/21 03:54:36 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fill_coord_value(char *str)
{
	int nbr;

	nbr = 0;
	if (*str && *str == '0')
		nbr = 0;
	else if (*str && *str > '0' && *str <= '9')
		nbr = ft_atoi(&(*str));
	return (nbr);
}

int			*fill_line(char **split, int max_x)
{
	int		a;
	int		*tab;

	tab = NULL;
	a = 0;
	if ((tab = (int *)malloc(sizeof(int) * max_x)) == NULL)
		error_system();
	while (split[a] && a < max_x)
	{
		tab[a] = fill_coord_value(split[a]);
		a++;
	}
	return (tab);
}

t_fdf		*parsing(int fd, int y, t_fdf *fdf)
{
	char	*n_line;
	char	**split;
	int		a;
	int		**tab;
	int		ret;

	ret = 0;
	fdf->max_y = y;
	a = 0;
	if ((tab = (int **)malloc(sizeof(int *) * fdf->max_y)) == NULL)
		error_system();
	while (get_next_line(fd, &n_line) == 1 && a < fdf->max_y)
	{
		split = ft_strsplit(n_line, ' ');
		if (a == 0)
			while (split[ret])
				ret++;
		tab[a] = fill_line(split, ret);
		//free_tab(split);
		ft_memdel((void **)&n_line);
		a++;
	}
	fdf->map = tab;
	fdf->max_x = ret;
	return (fdf);
}
