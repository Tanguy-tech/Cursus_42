/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:58:46 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 13:06:48 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		justify(t_printf *print_f, const char *pad)
{
	int i;

	i = 0;
	while (pad[i] == '0' || pad[i] == '-')
	{
		if (pad[i] == '0' && print_f->flags != 2)
			print_f->flags = 1;
		else if (pad[i] == '-')
			print_f->flags = 2;
		i++;
	}
	return (i);
}
