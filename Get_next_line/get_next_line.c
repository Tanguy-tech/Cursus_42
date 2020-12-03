/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:40:57 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/03 15:41:21 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_next(char *s, char c)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c && s[i])
	{
		j = 0;
		while (s[i + j])
			j++;
		if (!(next = ft_calloc(sizeof(char), j + 1)))
			return (0);
		j = 0;
		while (s[i])
		{
			next[j] = s[i];
			j++;
			i++;
		}
		next[j] = '\0';
		return (next);
	}
	return (0);
}

int		get_line(char **line, char **tmp, char **next, int val)
{
	*line = ft_substr(*tmp, 0, (ft_strlen(*tmp) - ft_strlen(*next)));
	*tmp = ft_substr(*next, 1, (ft_strlen(*next) - 1));
	return (val);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char *tmp[4096];
	char		*next;
	int			re;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (tmp[fd] == NULL)
		if (!(tmp[fd] = newstr(0)))
			return (-1);
	while (!(next = save_next(tmp[fd], '\n')))
	{
		if ((re = read(fd, buff, BUFFER_SIZE)) == 0)
			return (get_line(line, &tmp[fd], &next, 0));
		if (re == -1)
		{
			free(tmp[fd]);
			return (-1);
		}
		buff[re] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buff);
	}
	return (get_line(line, &tmp[fd], &next, 1));
}
