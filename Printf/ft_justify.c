/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:58:46 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/15 13:50:45 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		justify(t_Printf *print_f, const char *pad)
{
	int minus;
	int zero;
	int i;

	i = 0;
	minus = 0;
	zero = 0;
	while (pad[i] == '0' || pad[i] == '-')
	{
		if (pad[i] == '0')
			print_f->flags = 1;
		else if (pad[i] == '-')
			print_f->flags = 2;
		i++;
	}
	return (i);
}
