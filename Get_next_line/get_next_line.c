/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:40:57 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/02 16:46:46 by tbillon          ###   ########lyon.fr   */
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
	if (s[i++] == c && s[i])
	{
		j = i;
		while (s[j])
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

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char *tmp = NULL;
	char		*next;
	int			re;

	buff[BUFFER_SIZE] = '\0';
	if (tmp == NULL) 
		if(!(tmp = newstr(0)))
			return (-1);
	next = save_next(tmp, '\n');
	while (!next)
	{
		if ((re = read(fd, buff, BUFFER_SIZE)) == 0)
		{
			if (!next)
			{
				*line = NULL;
				return (0);
			}
		}
		if (re == -1)
			return (-1);
		tmp = ft_strjoin(tmp, buff);
		next = save_next(tmp, '\n');
	}
	*line = ft_substr(tmp, 0, (ft_strlen(tmp) - ft_strlen(next) - 1));
	free(tmp);
	tmp = next;
	return (1);
}
