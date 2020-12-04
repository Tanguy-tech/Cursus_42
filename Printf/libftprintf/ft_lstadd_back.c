/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:40:13 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/27 14:59:44 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			list = ft_lstlast(*(alst));
			list->next = new;
		}
	}
}
