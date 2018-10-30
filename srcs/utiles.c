/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:54:06 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/24 05:49:45 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ini_mlx(t_fdf *fdf)
{
	fdf->ha = 0;
	fdf->px = 0;
	fdf->py = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, MAX_X, MAX_Y, "fdf");
	n_image(fdf);
}

void		n_image(t_fdf *fdf)
{
	fdf->img = mlx_new_image(fdf->mlx, MAX_X, MAX_Y);
	fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sl, &fdf->edi);
	if (fdf->data == NULL)
		error_system();
	fdf->bpp /= 8;
}

void		pixel_to_img(t_fdf *f, int x, int y)
{
	if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
		*(unsigned int*)(f->data + (x * (f->bpp)) + (y * f->sl)) = f->co;
}

void		more_z(t_fdf *f)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a < f->max_y)
	{
		while (b < f->max_x)
		{
			if (f->map[a][b] == -1 && f->ha == 1)
				f->map[a][b] += 2;
			else if (f->map[a][b] == 1 && f->ha == -1)
				f->map[a][b] -= 2;
			else if (f->map[a][b] != 0)
				f->map[a][b] += f->ha;
			b++;
		}
		a++;
		b = 0;
	}
	f->ha = 0;
}
