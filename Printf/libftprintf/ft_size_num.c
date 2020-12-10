/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:21:51 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 15:17:39 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_num(int x)
{
	size_t i;

	i = 0;
	if (!x)
		return (0);
	while (x != 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}
