/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 23:51:30 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 01:15:56 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		size;
	char	*fresh;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	size = ft_calctrim(s);
	i = 0;
	k = 0;
	if ((fresh = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (ft_fisblank(s[i]) == 1)
		i++;
	while (k < size)
		fresh[k++] = s[i++];
	fresh[k] = '\0';
	return (fresh);
}
