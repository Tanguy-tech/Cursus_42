/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:55:21 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/07 10:11:09 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (str[j])
		{
			if (i == j)
				j++;
			else if (str[i] == str[j])
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	if (ft_strlen(str) <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		k;
	long	nb;

	i = 0;
	nb = nbr;
	k = ft_strlen(base);
	if (check(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb >= k)
		{
			ft_putnbr_base((nb / k), base);
		}
		ft_putchar(base[nb % k]);
	}
}
