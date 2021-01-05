/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:23:05 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 09:20:55 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, int size)
{
	char			*tab;
	unsigned long	i;

	i = 0;
	if (!(tab = malloc(size * count)))
		return (0);
	while (i < (size * count))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
