/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:12:50 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 01:19:46 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calctrim(char const *str)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (str[i] && ft_fisblank(str[i]) == 1)
	{
		result++;
		i++;
	}
	if (result == (int)ft_strlen(str))
		return (0);
	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_fisblank(str[i]) == 1)
	{
		result++;
		i--;
	}
	return (ft_strlen(str) - result);
}
