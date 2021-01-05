/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:19:11 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/21 16:34:59 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill(char *str, int index, char *base, unsigned long n)
{
	unsigned long len;

	len = ft_strlen(base);
	if (n >= len)
	{
		fill(str, index - 1, base, n / len);
	}
	str[index] = base[n % len];
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	char			*str;
	int				len;

	len = ft_size_num_base(n, ft_strlen(base));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	fill(str, len - 1, base, n);
	str[len] = '\0';
	return (str);
}
