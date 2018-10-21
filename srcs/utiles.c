/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:54:06 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/21 04:24:43 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ini_mlx(t_fdf *fdf)
{
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

void		pixel_to_img(t_fdf *fdf, int x, int y)
{
	int		c;

	c = BLUE;
	if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
		*(unsigned int*)(fdf->data + (x * (fdf->bpp)) + (y * fdf->sl)) = c;
}
