/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 04:08:23 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/13 04:24:17 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	a;
	int b;

	a = 0;
	b = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[a])
	{
		while (haystack[a + b] == needle[b])
		{
			if (needle[b + 1] == '\0')
				return ((char *)haystack + a);
			b++;
		}
		b = 0;
		a++;
	}
	return (NULL);
}
