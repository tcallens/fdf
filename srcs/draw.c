/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:08:46 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/24 05:49:53 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coord_hor(t_point *p, t_fdf *f, int x, int y)
{
	p->x1 = f->st_x + (x - y) * f->zo + f->px;
	p->y1 = f->st_y + (x + y) * f->zo - (f->map[y][x] * 2) + f->py;
	p->x2 = f->st_x + ((x + 1) - y) * f->zo + f->px;
	p->y2 = f->st_y + ((x + 1) + y) * f->zo - (f->map[y][x + 1] * 2) + f->py;
	p->dx = (float)(p->x2 - p->x1);
	p->dy = (float)(p->y2 - p->y1);
}

void	set_coord_ver(t_point *p, t_fdf *f, int x, int y)
{
	p->x1 = f->st_x + (x - y) * f->zo + f->px;
	p->y1 = f->st_y + (x + y) * f->zo - (f->map[y][x] * 2) + f->py;
	p->x2 = f->st_x + (x - (y + 1)) * f->zo + f->px;
	p->y2 = f->st_y + (x + (y + 1)) * f->zo - (f->map[y + 1][x] * 2) + f->py;
	p->dx = (float)(p->x2 - p->x1);
	p->dy = (float)(p->y2 - p->y1);
}

void	set_coord(t_fdf *fdf, int x, int y)
{
	t_point	p;
	int		a;
	int		b;
	double	tx;

	tx = 0.0;
	if (x < fdf->max_x - 1)
		set_coord_hor(&p, fdf, x, y);
	while (tx <= 1 && x < fdf->max_x - 1)
	{
		a = p.x1 + (p.dx * tx);
		b = p.y1 + (p.dy * tx);
		pixel_to_img(fdf, a, b);
		tx += 1. / sqrt((p.dx * p.dx) + (p.dy * p.dy));
	}
	tx = 0.0;
	if (y < fdf->max_y - 1)
		set_coord_ver(&p, fdf, x, y);
	while (tx <= 1 && y < fdf->max_y - 1)
	{
		a = p.x1 + (p.dx * tx);
		b = p.y1 + (p.dy * tx);
		pixel_to_img(fdf, a, b);
		tx += 1. / sqrt((p.dx * p.dx) + (p.dy * p.dy));
	}
}

int		fill_img(t_fdf *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	more_z(f);
	f->st_x = (MAX_X / 2) - (f->max_x * f->zo) / 2;
	f->st_y = (MAX_Y / 2) - (f->max_y * f->zo) / 2;
	while (y < f->max_y)
	{
		while (x < f->max_x)
		{
			find_color(f, x, y);
			set_coord(f, x, y);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (1);
}

void	find_color(t_fdf *f, int x, int y)
{
	f->co = SKY;
	if (f->map[y][x] > 0 || (x + 1 < f->max_x && f->map[y][x + 1] > 0))
		f->co = RED;
	if (f->map[y][x] > 0 || (y + 1 < f->max_y && f->map[y + 1][x] > 0))
		f->co = RED;
	if (f->map[y][x] < 0 || (x + 1 < f->max_x && f->map[y][x + 1] < 0))
		f->co = BLUE;
	if (f->map[y][x] < 0 || (y + 1 < f->max_y && f->map[y + 1][x] < 0))
		f->co = BLUE;
}
