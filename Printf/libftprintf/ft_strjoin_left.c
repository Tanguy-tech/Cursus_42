/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:57:33 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 09:48:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_left(char c, char *str)
{
	char	*tab;
	int		i;
	int		j;

	if (!str)
		return (0);
	if (!(tab = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (0);
	i = 0;
	tab[i] = c;
	i++;
	j = 0;
	while (str[j])
	{
		tab[i] = str[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	free(str);
	return (tab);
}
