/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:07:31 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/06 19:33:12 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int		y;
	int 	fd;
	t_fdf	*fdf;
	int		a;

	a = 0;
	if (ac < 2 || ac >= 3)
		ac_error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	if ((fdf = (t_fdf *)malloc(sizeof(t_fdf))) == NULL)
		error_system();
	y = check_valid_file(fd);
	close(fd);
	if((fd = open(av[1], O_RDONLY)) == -1)
		file_error();
	fdf = parsing(fd, y, fdf);
	a = 0;
	while (a < fdf->max_y)
	{
		while (fdf->line[a])
		{
			ft_putnbr(fdf->line[a]->height);
			ft_putstr(" ");
			if (fdf->line[a]->next == NULL)
				break;
			fdf->line[a] = fdf->line[a]->next;
			if (fdf->line[a]->height < 10)
				ft_putstr(" ");
		}
		ft_putendl("");
		a++;
	}
	while (1);
	return (1);
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
