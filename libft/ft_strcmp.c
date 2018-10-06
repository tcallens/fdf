/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 01:35:40 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/15 01:39:15 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int a;

	a = 0;
	while ((s1[a] || s2[a]) && s1[a] == s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
