/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:10:13 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/26 11:23:37 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			count;
	unsigned char	*from;
	unsigned char	*dest;

	count = len;
	from = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (len == 0 || dest == from)
		return (dest);
	if (dest > from)
	{
		while (count)
		{
			count--;
			(dest[count] = from[count]);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dest);
}
