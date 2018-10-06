/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:46:56 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 00:47:04 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int words;
	int i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			words++;
		i++;
	}
	return (words);
}
