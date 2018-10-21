/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:07:31 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/21 04:27:40 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		y;
	int 	fd;
	t_fdf	fdf;

	fdf.zo = 1;
	if (ac < 2 || ac >= 3)
		ac_error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	y = check_valid_file(fd);
	close(fd);
	if((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	parsing(fd, y, &fdf);
	//ttry(fdf);
	ini_mlx(&fdf);
	fill_img(&fdf);
	mlx_hook(fdf.win, 2, 1, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (1);
}

void		ttry(t_fdf *fdf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < fdf->max_y)
	{
		while (x < fdf->max_x)
		{
			ft_putnbr(fdf->map[y][x]);
			ft_putstr(" ");
			if (fdf->map[y][x + 1] < 10)
				ft_putstr(" ");
			x++;
		}
		ft_putendl("");
		y++;
		x = 0;
	}
}
/*int			main(void)
  {
  void	*mlx_ptr;
  void	*win_ptr;
  int a;

  a = 310;
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, MAX_X, MAX_Y, "BITE");
  while (a < 410)
  {
  mlx_pixel_put(mlx_ptr, win_ptr, 540, a, 0xFFFFFF);
  a++;
  }
  a = 500;
  while (a < 580)
  {
  mlx_pixel_put(mlx_ptr, win_ptr, a, 310, 0xFFFFFF);
  a++;
  }

  mlx_loop(mlx_ptr);
  return (1);
  }*/
