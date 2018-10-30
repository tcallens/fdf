/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:01:19 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/24 05:48:00 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>

# define MAX_X	1920
# define MAX_Y	1080

# define BLUE 0x0901F7
# define BLUE_C 0x015BF7
# define SKY 0x01B5F7
# define LAGON 0x33AB9B
# define WGREEN 0x01F79D
# define RAZER 0x01F74B
# define LIMON 0xADF701
# define YELLOW 0xEFF701
# define ORANGE 0xF78C01
# define RED 0xFE4D01
# define BACKGROUND 0x4C1B1B

/*
** -------------------------------- Struct -------------------------------------
*/

typedef	struct			s_point
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	float				dx;
	float				dy;
}						t_point;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					**map;
	int					max_y;
	int					max_x;
	int					zo;
	int					st_x;
	int					st_y;
	int					bpp;
	int					sl;
	int					edi;
	int					px;
	int					py;
	int					co;
	int					ha;
}						t_fdf;

/*
** ------------------------------- Fonction ------------------------------------
*/

/*
** -=-=- utiles.c -=-=-
*/

void					ini_mlx(t_fdf *fdf);
void					n_image(t_fdf *fdf);
void					pixel_to_img(t_fdf *f, int x, int y);
void					more_z(t_fdf *f);

/*
** -=-=- draw.c -=-=-
*/

void					set_coord_hor(t_point *p, t_fdf *f, int x, int y);
void					set_coord_ver(t_point *p, t_fdf *f, int x, int y);
void					set_coord(t_fdf *fdf, int x, int y);
int						fill_img(t_fdf *f);
void					find_color(t_fdf *f, int x, int y);

/*
** -=-=- free.c -=-=-
*/

void					free_tab(int **tab, int may);
void					free_split(char **tab, int max);

/*
** -=-=- pars.c -=-=-
*/

int						fill_coord_value(char *str);
int						*fill_line(char **split, int max_x);
t_fdf					*parsing(int fd, int y, t_fdf *fdf);

/*
** -=-=- check_valid.c -=-=-
*/

int						check_hex(char *line);
int						check_valid_line(char *line);
int						check_valid_file(int fd);

/*
** -=-=- hook.c -=-=-
*/

void					key_listener(int keycode, t_fdf *f);
int						key_hook(int keycode, t_fdf *f);

/*
** -=-=- error.c -=-=-
*/

void					error_system(void);
void					bad_map(int a);
void					ac_error(void);
void					file_error(void);

#endif
