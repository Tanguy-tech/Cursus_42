/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:23:38 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/26 10:06:26 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*string;

	count = 0;
	string = (unsigned char *)s;
	while (count < n)
	{
		if (string[count] == (unsigned char)c)
			return (string + count);
		count++;
	}
	return (0);
}
