/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:58:46 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 13:44:23 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		justify(t_Printf *print_f, const char *pad)
{
	int minus;
	int plus;
	int i;

	i = 0;
	minus = 0;
	plus = 0;
	while (pad[i] == '+' || pad[i] == '-')
	{
		if (pad[i] == '-')
			minus++;
		if (pad[i] == '+')
			plus++;
		i++;
	}
	if (plus > 0)
		print_f->flags = 3;
	else
		print_f->flags = 2;
	return (i);
}