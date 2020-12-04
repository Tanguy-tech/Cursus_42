/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:04:59 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/28 12:23:01 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_el;

	if (!lst || !f)
		return (0);
	new = 0;
	while (lst)
	{
		if (!(new_el = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_el, del);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, new_el);
		lst = lst->next;
	}
	return (new);
}
