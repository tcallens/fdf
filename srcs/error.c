/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:08:34 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/22 18:27:00 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ac_error(void)
{
	ft_putstr_fd("usage: ./fdf [map_file]\n", 2);
	exit(EXIT_FAILURE);
}

void	file_error(void)
{
	perror("error ");
	exit(EXIT_FAILURE);
}

void	bad_map(int a)
{
	int	y;

	y = a;
	ft_putstr_fd("error : Map invalid\n", 2);
	exit(EXIT_FAILURE);
}

void	error_system(void)
{
	ft_putstr_fd("error system\n", 2);
	exit(EXIT_FAILURE);
}
