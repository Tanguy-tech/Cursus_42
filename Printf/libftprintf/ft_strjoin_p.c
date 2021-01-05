/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:16:10 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/21 16:00:07 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_p(char *s1, char *s2)
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
