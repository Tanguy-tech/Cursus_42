/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 07:58:46 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 08:13:53 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		justify(t_Printf *print_f, va_list args, char pad)
{
	if (pad == '-')
		print_f->flags = 2;
	else if (pad == '+')
		print_f->flags = 3;
	return (1);
}
