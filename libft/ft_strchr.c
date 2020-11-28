/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:25:16 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/26 10:37:21 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	to_find;
	char			*haystack;

	i = 0;
	to_find = (unsigned char)c;
	haystack = (char *)s;
	while (haystack[i])
		i++;
	if ((to_find) == '\0')
		return (&haystack[i]);
	i = 0;
	while (haystack[i] != to_find && haystack[i])
		i++;
	if (haystack[i] != '\0')
		return (haystack + i);
	else
		return (0);
}
