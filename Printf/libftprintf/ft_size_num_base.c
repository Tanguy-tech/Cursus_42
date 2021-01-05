/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_num_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:21:51 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/21 16:15:19 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_num_base(unsigned long x, int base)
{
	size_t i;

	i = 0;
	if (x == 0)
		return (1);
	if (!x)
		return (0);
	while (x != 0)
	{
		x = x / base;
		i++;
	}
	return (i);
}
