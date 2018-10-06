/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 03:42:16 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 00:58:04 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	if (s2 < s1)
	{
		while (n--)
			s1[n] = s2[n];
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
