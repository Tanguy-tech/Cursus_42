/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:33:43 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/26 10:16:38 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	i = 0;
	s1_ = (unsigned char *)s1;
	s2_ = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
		i++;
	}
	return (0);
}
