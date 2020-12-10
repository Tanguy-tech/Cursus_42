/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:17:52 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 14:55:24 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str, int prec)
{
	int i;

	i = 0;
	prec = ft_abs(prec);
	while (str[i] != '\0' && i < prec)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
