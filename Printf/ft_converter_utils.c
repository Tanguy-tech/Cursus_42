/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:46:12 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 08:57:34 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pad_width(t_Printf *print_f, char *str)
{
	if (print_f->type == 'p')
	{
		if (print_f->flags == 2)
			print_f->result += ft_putstr("0x") + ft_putstr(str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				print_f->result += ft_putstr("0x") + ft_putstr(str);
		}
	}
	else
	{
		if (print_f->flags == 2)
			print_f->result += ft_putstr(str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				print_f->result += ft_putstr(str);
		}
	}
}

void	num_pad_width(t_Printf *print_f, int i)
{
	if (print_f->flags == 2)
		print_f->result += ft_putstr(ft_itoa(i));
	if (print_f->width >= 0)
	{
		write_width_num(print_f, i);
		if (print_f->flags != 2)
			print_f->result += ft_putstr(ft_itoa(i));
	}
}