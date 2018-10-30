/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 04:18:55 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/22 18:15:45 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				key_listener(int keycode, t_fdf *f)
{
	if (keycode == 53)
	{
		free_tab(f->map, f->max_y);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 4)
		f->ha = 1;
	if (keycode == 38)
		f->ha = -1;
	if (keycode == 126)
		f->py += 20;
	if (keycode == 125)
		f->py -= 20;
	if (keycode == 123)
		f->px -= 20;
	if (keycode == 124)
		f->px += 20;
	if (keycode == 69)
		f->zo += 1;
	if (keycode == 78)
		if (f->zo > 1)
			f->zo -= 1;
}

int					key_hook(int keycode, t_fdf *f)
{
	key_listener(keycode, f);
	mlx_destroy_image(f->mlx, f->img);
	n_image(f);
	mlx_clear_window(f->mlx, f->win);
	fill_img(f);
	return (0);
}
