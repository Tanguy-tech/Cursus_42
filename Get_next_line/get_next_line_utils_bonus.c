/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:40:53 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/03 09:22:01 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;

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

char	*newstr(int len)
{
	char *new;

	if (!(new = ft_calloc(sizeof(char), len + 1)))
		return (0);
	new[len] = '\0';
	return (new);
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
	if (!(tab = ft_calloc(sizeof(char), len_tot + 1)))
		return (0);
	while (s1[++i] && i < len_tot)
		tab[i] = s1[i];
	while (s2[++j] && i < len_tot)
		tab[i++] = s2[j];
	tab[i] = '\0';
	free(s1);
	return (tab);
}

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
		if (!(tab = ft_calloc(sizeof(char), 1)))
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	if (!(tab = ft_calloc(sizeof(char), len + 1)))
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
