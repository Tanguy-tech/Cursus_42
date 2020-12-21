/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:19:11 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/13 15:24:44 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long n, char *base)
{
	char			*str;
	unsigned long	i;

	i = ft_strlen(base);
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n >= i)
		str = ft_strjoin(ft_itoa_base(n / i, base), ft_itoa_base(n % i, base));
	else if (n < i)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
