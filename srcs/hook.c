/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 04:18:55 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/21 04:37:58 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				key_listener(int keycode, t_fdf *f)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
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
		f->zo -= 1;
}

int					key_hook(int keycode, t_fdf *f)
{
	key_listener(keycode, f);
	mlx_destroy_image(f->mlx, f->img);
	n_image(f);
	fill_img(f);
	//mlx_clear_window(f->env.mlx, f->env.win);
	//mlx_put_image_to_window(f->env.mlx, f->env.win, f->img.img, 0, 0);
	return (0);
}
