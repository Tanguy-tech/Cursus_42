/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:46:12 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/13 16:05:01 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pad_width(t_Printf *print_f, char *str)
{
	if (print_f->type == 'p')
	{
		str = ft_strjoin("0x", str);
		if (print_f->flags == 2)
			write_precision(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision(print_f, str);
		}
	}
	else
	{
		if (print_f->flags == 2)
			write_precision(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision(print_f, str);
		}
	}
}

void	num_pad_width(t_Printf *print_f, int i)
{
	if (print_f->flags == 23)
	{
		print_f->result += ft_putchar('+');
		print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i) + 1);
	}
	if (print_f->flags == 2)
		write_precision_diu(print_f, i);
	if (print_f->width >= 0)
	{
		write_width_num(print_f, i);
		if (print_f->flags != 2 && print_f->flags != 3 && print_f->flags != 23)
			write_precision_diu(print_f, i);
	}
	if (print_f->flags == 3)
	{
		if (print_f->flags == 3)
			print_f->result += ft_putchar('+');
		write_precision_diu(print_f, i);
	}
}

void	star_condition(t_Printf *print_f, va_list args)
{
	if (print_f->star == 1)
		print_f->width = va_arg(args, int);
	if (print_f->width < 0)
	{
		print_f->width = ft_abs(print_f->width);
		print_f->flags = 2;
	}
}
