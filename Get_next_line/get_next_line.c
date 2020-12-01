/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 05:40:57 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/01 08:05:24 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **s)
{
	char *tmp;

	tmp = *s;
	free(tmp);
	*s = NULL;
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char *membuff;
	char		*end_line;

	buff[BUFFER_SIZE] = '\0'; /* on met '\0' a la fin de la chaine buff longue de BUFFER_SIZE */
	if (membuff == NULL)
	{
			if (!(membuff = new_str(0))) /* creation de membuff -> initialisation a len 0 */
				return (-1);
	}
	else if ((end_line = ft_strchr(membuff, '\n')))
	{
		*line = ft_substr(membuff, 0, ft_strlen(membuff) - ft_strlen(end_line) - 1);
		membuff = end_line;
		return (1);
	}
	while ((read(fd, buff, BUFFER_SIZE)) > 0) /* tant qu'il est possible de lire le fichier  */
	{
			membuff = ft_strjoin(membuff, buff);
		if ((end_line = ft_strchr(membuff, '\n')))
		{
			*line = ft_substr(membuff, 0, ft_strlen(membuff) - ft_strlen(end_line) - 1);
			membuff = end_line;
			return (1);
		}
	}
	if (ft_strlen(membuff) > 0)
	{
		*line = membuff;
		ft_free(&membuff);
		return (1);
	}
	ft_free(&membuff);
	*line = membuff;
	return (0);
}
