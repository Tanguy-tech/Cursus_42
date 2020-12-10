/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:37:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 13:11:06 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision(t_Printf *print_f, const char *prec)
{
	int		i;
	char	*str_precision;

	i = 0;
	while (ft_isdigit(prec[i]) == 1)
		i++;
	if (!(str_precision = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (ft_isdigit(prec[i]) == 1)
	{
		str_precision[i] = prec[i];
		i++;
	}
	str_precision[i] = '\0';
	print_f->precision += ft_atoi(str_precision);
	i = ft_strlen(str_precision);
	return (i);
}
