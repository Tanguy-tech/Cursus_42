/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:41:08 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/27 12:10:28 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*haystack;
	char	car;
	int		i;

	i = 0;
	car = (char)c;
	haystack = (char *)s;
	while (haystack[i])
		i++;
	while (i >= 0)
	{
		if (haystack[i] == car)
			return (haystack + i);
		i--;
	}
	return (0);
}
