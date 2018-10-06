/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:01:19 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/06 19:27:00 by tcallens         ###   ########.fr       */
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

/*
** -------------------------------- Struct -------------------------------------
*/

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	struct s_line		**line;
	int					max_y;
	int					max_x;
}						t_fdf;

typedef struct			s_line
{
	int					height;
	char				*color;
	int					x;
	int					y;
	int					maxx_x;
	struct s_line		*next;
}						t_line;

/*
** ------------------------------- Fonction ------------------------------------
*/

/*
** -=-=- free.c -=-=-
*/

void			free_tab(char **str);
void			free_list(t_line **line, int x, int y);

/*
** -=-=- pars.c -=-=-
*/

t_line			*fill_coord_value(char *str, int y, int x, t_line *line);
t_line			*fill_line(int y, char **split);
t_fdf			*parsing(int fd, int y, t_fdf *fdf);

/*
** -=-=- check_valid.c -=-=-
*/

int				check_hex(char *line);
void			check_valid_line(char *line);
int				check_valid_file(int fd);

/*
** -=-=- error.c -=-=-
*/

void			error_system(void);
void			bad_map(int a);
void			ac_error(void);
void			file_error(void);

#endif
