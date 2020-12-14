/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:50 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/14 12:55:34 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaces_type_width(t_Printf *print_f, int len)
{
	int i;

	i = 0;
	while (i < (print_f->width - len))
	{
		print_f->result += ft_putchar(' ');
		i++;
	}
}

void	zero_type_width(t_Printf *print_f, int len)
{
	int i;

	i = 0;
	while (i < (print_f->width - len))
	{
		print_f->result += ft_putchar('0');
		i++;
	}
}

void	write_width_c(t_Printf *print_f)
{
	if (print_f->flags == 1)
		zero_type_width(print_f, 1);
	else
		spaces_type_width(print_f, 1);
}

void	write_width_str(t_Printf *print_f, char *str)
{
	if (print_f->flags == 1)
		zero_type_width(print_f, ft_strlen(str));
	else
	{
		if (print_f->precision > 0)
		{
			if (print_f->precision > ft_strlen(str))
				print_f->width += print_f->precision - ft_strlen(str);
			spaces_type_width(print_f, print_f->precision);
		}
		if (print_f->precision < 0)
			spaces_type_width(print_f, 0);
		else if (print_f->precision == 0)
		{
			if (print_f->flags == 2)
				spaces_type_width(print_f, ft_strlen(str) + 1);
			else
				spaces_type_width(print_f, ft_strlen(str));
		}
	}
}

void	write_width_num(t_Printf *print_f, int num)
{
	if (print_f->flags == 1)
	{
		if (num <= 0)
			zero_type_width(print_f, ft_size_num(num) + 1);
		else
			zero_type_width(print_f, ft_size_num(num));
	}
	else
	{
		if (print_f->precision > 0)
		{
			if (print_f->precision > ft_size_num(num))
			{
				if (print_f->width > print_f->precision)
					spaces_type_width(print_f, print_f->precision);
			}
			if (print_f->precision == print_f->width)
			{
				if (print_f->precision > ft_size_num(num))
					zero_type_width(print_f, ft_size_num(num));
			}
			if (print_f->precision > print_f->width && print_f->flags != 2)
			{
				print_f->width = print_f->precision;
				zero_type_width(print_f, ft_size_num(num));
			}
		}
		else if (print_f->flags == 23)
			spaces_type_width(print_f, ft_size_num(num) + 1);
		else
			spaces_type_width(print_f, ft_size_num(num));
	}
}
