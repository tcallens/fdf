/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:56:20 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/22 19:12:42 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_hex(char *line)
{
	int		a;

	a = 0;
	line++;
	if (*line && *line != '0')
		bad_map(1);
	line++;
	if (*line && *line != 'x')
		bad_map(2);
	line++;
	while (*line && *line != ' ')
	{
		if ((*line < '0' || *line > '9') && (*line < 'A' || *line > 'F')
				&& (*line < 'a' || *line > 'f'))
			bad_map(3);
		line++;
		a++;
	}
	if (a < 2 || a > 6)
		bad_map(4);
	return (a);
}

int			check_valid_line(char *line)
{
	int		a;

	a = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line && *line == '-')
			line++;
		if (!*line || *line < '0' || *line > '9')
			bad_map(5);
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		a++;
		if (*line == '\0')
			break ;
		if (*line == ',')
			line += check_hex(&(*line)) + 3;
		if (*line == '\0')
			break ;
		while (*line && *line == ' ')
			line++;
	}
	return (a);
}

int			check_valid_file(int fd)
{
	int		a;
	int		b;
	int		ret;
	char	*new_line;
	int		y;

	a = 0;
	b = 0;
	y = 0;
	while ((ret = get_next_line(fd, &new_line)) == 1)
	{
		a = check_valid_line(new_line);
		ft_memdel((void **)&new_line);
		if (a != b && y > 0)
			bad_map(6);
		y++;
		b = a;
	}
	if (ret == -1)
		bad_map(6);
	ft_memdel((void **)&new_line);
	return (y);
}
