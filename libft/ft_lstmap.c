/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:30:12 by tcallens          #+#    #+#             */
/*   Updated: 2017/11/22 00:30:36 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *addr;

	if (lst == NULL)
		return (NULL);
	if (!(fresh = (t_list *)malloc(sizeof(t_list))))
		return (0);
	fresh = f(ft_lstnew(lst->content, lst->content_size));
	addr = fresh;
	lst = lst->next;
	while (lst)
	{
		if (!(addr->next = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		lst = lst->next;
		addr = addr->next;
	}
	return (fresh);
}
