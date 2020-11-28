/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:12:47 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/26 09:45:40 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*from;
	unsigned char	*dest;

	count = 0;
	from = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (count < n && from[count] != (unsigned char)c)
	{
		dest[count] = from[count];
		count++;
	}
	if (count == n)
		return (0);
	else
	{
		dest[count] = from[count];
		count++;
	}
	return (&dest[count]);
}
