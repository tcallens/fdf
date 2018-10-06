/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:16:54 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/06 19:22:20 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_tab(char **str)
{
	int		a;

	a = 0;
	while (str[a])
		free(str[a++]);
	free(str);
}

void		free_list(t_line **line, int x, int y)
{
	int		a;
	int		b;
	t_line	*tmp;

	a = 0;
	b = 0;
	while (a < y)
	{
		while (b < x)
		{
			tmp = line[a]->next;
			free(line[a]);
			line[a] = tmp;
			b++;
		}
		a++;
	}
}
