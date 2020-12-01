/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:40:53 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/01 08:00:32 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		i;
	size_t		s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		if (!(tab = malloc(sizeof(char) * 1)))
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	free(s);
	return (tab);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		len_tot;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	if (!(tab = malloc(sizeof(char) * (len_tot + 1))))
		return (0);
	while (s1[++i] && i < len_tot)
		tab[i] = s1[i];
	while (s2[++j] && i < len_tot)
		tab[i++] = s2[j];
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	to_find;
	char			*haystack;
	char			*mal;

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
		return (haystack + i + 1);
	else
		return (0);
}

char	*new_str(int len)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	return (new_str);
}