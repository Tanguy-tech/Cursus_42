/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 08:42:31 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/26 09:51:10 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*dest;

	i = 0;
	from = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (n == 0 || dest == from)
		return (dest);
	while (i < n)
	{
		dest[i] = from[i];
		i++;
	}
	return (dest);
}
