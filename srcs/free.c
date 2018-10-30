/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:16:54 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/22 17:07:35 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_tab(int **tab, int may)
{
	int		a;

	a = 0;
	while (a < may)
	{
		free((void *)tab[a]);
		a++;
	}
	free(tab);
}

void		free_split(char **tab, int max)
{
	int		a;

	a = 0;
	while (tab[a] && a < max)
		free(tab[a++]);
	free(tab);
}
