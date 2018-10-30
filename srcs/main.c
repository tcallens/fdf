/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:07:31 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/24 05:50:00 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		y;
	int		fd;
	t_fdf	fdf;

	fdf.zo = 10;
	if (ac < 2 || ac >= 3)
		ac_error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	y = check_valid_file(fd);
	close(fd);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	parsing(fd, y, &fdf);
	ini_mlx(&fdf);
	if (fdf.max_y > 50)
		fdf.zo = 2;
	fill_img(&fdf);
	mlx_hook(fdf.win, 2, 1, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (1);
}
