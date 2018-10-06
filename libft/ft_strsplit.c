/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:47:45 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 00:47:56 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		tab_size;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	tab_size = ft_countwords(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * tab_size + 1)) == NULL)
		return (NULL);
	while (tab_size--)
	{
		while (*s == c && *s)
			s++;
		if ((tab[i++] = ft_strsub(s, 0, ft_wordlen(s, c))) == NULL)
			return (NULL);
		s += ft_wordlen(s, c);
	}
	tab[i] = NULL;
	return (tab);
}
