/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:25:42 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/14 17:10:39 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	define_convert_args(t_Printf *print_f, va_list args, char type)
{
	if (type == 'c' || type == 's')
		convert_cs(print_f, args);
	else if (type == 'd' || type == 'i' || type == 'u')
		convert_num(print_f, args);
	else if (type == 'p' || type == 'x' || type == 'X')
		convert_pxx(print_f, args);
	else if (type == '%')
		convert_percent(print_f);
}

void	convert_cs(t_Printf *print_f, va_list args)
{
	char c;
	char *str;

	if (print_f->type == 'c')
	{
		star_condition(print_f);
		c = va_arg(args, int);
		if (print_f->flags == 2)
			print_f->result += ft_putchar(c);
		if (print_f->width >= 0)
		{
			write_width_c(print_f);
			if (print_f->flags != 2)
				print_f->result += ft_putchar(c);
		}
	}
	if (print_f->type == 's')
	{
		star_condition(print_f);
		str = va_arg(args, char*);
		if (print_f->precision == -1)
			str = NULL;
		str_pad_width(print_f, str);
	}
}

void	convert_num(t_Printf *print_f, va_list args)
{
	int i;

	if (print_f->type == 'd' || print_f->type == 'u')
	{
		star_condition(print_f);
		i = va_arg(args, int);
		num_pad_width(print_f, i);
	}
	if (print_f->type == 'i')
	{
		star_condition(print_f);
		i = va_arg(args, unsigned int);
		if (print_f->flags == 2 || print_f->flags == 3)
		{
			if (print_f->flags == 3)
				print_f->result += ft_putchar('+');
			print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
		}
		if (print_f->width >= 0)
		{
			write_width_num(print_f, i);
			if (print_f->flags != 2 && print_f->flags != 3)
				print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
		}
	}
}

void	convert_pxx(t_Printf *print_f, va_list args)
{
	char	*str;

	if (print_f->type == 'p')
	{
		star_condition(print_f);
		if (print_f->width == -1)
			print_f->width = va_arg(args, long) - 2;
		str = ft_itoa_base(va_arg(args, unsigned long), "0123456789abcdef");
		str_pad_width(print_f, str);
	}
	if (print_f->type == 'x')
	{
		star_condition(print_f);
		str = ft_itoa_base(va_arg(args, unsigned long), "0123456789abcdef");
		str_pad_width(print_f, str);
	}
	if (print_f->type == 'X')
	{
		star_condition(print_f);
		str = ft_itoa_base(va_arg(args, unsigned long), "0123456789ABCDEF");
		str_pad_width(print_f, str);
	}
}

void	convert_percent(t_Printf *print_f)
{
	star_condition(print_f);
	if (print_f->flags == 2)
		print_f->result += ft_putchar('%');
	if (print_f->width > 0)
	{
		write_width_c(print_f);
		if (print_f->flags != 2)
			print_f->result += ft_putchar('%');
	}
}
