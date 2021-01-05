/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:57:33 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 09:48:00 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_c(char c, char *str)
{
	char	*tab;
	int		i;

	if (!str)
		return (0);
	if (!(tab = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (0);
	i = 0;
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = c;
	tab[i + 1] = '\0';
	free(str);
	return (tab);
}
