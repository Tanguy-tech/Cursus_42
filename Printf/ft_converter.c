/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:25:42 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/10 08:58:30 by tbillon          ###   ########lyon.fr   */
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
		convert_percent(print_f, args);
}

void	convert_cs(t_Printf *print_f, va_list args)
{
	char c;
	char *str;

	if (print_f->type == 'c')
	{
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
		str = va_arg(args, char*);
		str_pad_width(print_f, str);
	}
}

void	convert_num(t_Printf *print_f, va_list args)
{
	int i;

	if (print_f->type == 'd' || print_f->type == 'u')
	{
		i = va_arg(args, int);
		num_pad_width(print_f, i);
	}
	if (print_f->type == 'i')
	{
		i = va_arg(args, unsigned int);
		if (print_f->flags == 2)
			print_f->result += ft_putstr(ft_itoa(i));
		if (print_f->width >= 0)
		{
			write_width_num(print_f, i);
			if (print_f->flags != 2)
				print_f->result += ft_putstr(ft_itoa(i));
		}
	}
}

void	convert_pxx(t_Printf *print_f, va_list args)
{
	char	*str;

	if (print_f->type == 'p')
	{
		str = ft_itoa_base(va_arg(args, long), "0123456789abcdef");
		str_pad_width(print_f, str);
	}
	if (print_f->type == 'x')
	{
		str = ft_itoa_base(va_arg(args, int), "0123456789abcdef");
		str_pad_width(print_f, str);
	}
	if (print_f->type == 'X')
	{
		str = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF");
		str_pad_width(print_f, str);
	}
}

void	convert_percent(t_Printf *print_f, va_list args)
{
	if (print_f->flags == 2)
		print_f->result += ft_putchar('%');
	if (print_f->width > 0)
	{
		write_width_c(print_f);
		if (print_f->flags != 2)
			print_f->result += ft_putchar('%');
	}
}
