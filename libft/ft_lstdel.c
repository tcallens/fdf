/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:26:15 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 00:26:24 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *tmp;

	list = *alst;
	while (list)
	{
		tmp = list;
		del(list->content, list->content_size);
		list = list->next;
		free(tmp);
	}
	*alst = NULL;
}
