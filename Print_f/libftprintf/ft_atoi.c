/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:23:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/21 13:18:11 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	size_t i;
	size_t neg;
	size_t res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				neg++;
		while (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i++] - 48);
		if (neg % 2 == 1)
			res = res * -1;
		return (res);
	}
	return (0);
}
