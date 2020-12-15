/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:46:12 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/15 13:29:17 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pad_width(t_Printf *print_f, char *str)
{
	if (print_f->type == 'p')
	{
		str = ft_strjoin("0x", str);
		if (print_f->flags == 2)
			write_precision_str(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision_str(print_f, str);
		}
	}
	else
	{
		if (print_f->flags == 2)
			write_precision_str(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision_str(print_f, str);
		}
	}
}

void	num_pad_width(t_Printf *print_f, int i)
{
	if (print_f->type == 'd')
	{
		if (print_f->precision == -1 && i == 0)
			print_f->result = 0;
		else if (print_f->width > print_f->precision)
			write_precision_num_1(print_f, i);
		else if (print_f->width < print_f->precision)
			write_precision_num_2(print_f, i);
		else if (print_f->width == print_f->precision)
			write_precision_num_3(print_f, i);
	}
}

void	star_condition(t_Printf *print_f)
{
	if (print_f->width < 0)
	{
		print_f->width = ft_abs(print_f->width);
		print_f->flags = 2;
	}
}
