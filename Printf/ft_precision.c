/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:37:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/14 17:25:12 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision(t_Printf *print_f, va_list args, const char *prec)
{
	int		i;
	char	*str_precision;

	i = 0;
	if (prec[i] == '*')
	{
		print_f->precision = va_arg(args, int);
		return (1);
	}
	if (ft_isdigit(prec[i]) == 0 || prec[i] == '0')
	{
		print_f->precision = -1;
		return (1);
	}
	while (ft_isdigit(prec[i]) == 1)
		i++;
	if (!(str_precision = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (ft_isdigit(prec[i]) == 1)
	{
		str_precision[i] = prec[i];
		i++;
	}
	str_precision[i] = '\0';
	print_f->precision = ft_atoi(str_precision);
	i = ft_strlen(str_precision);
	return (i);
}

void	write_precision(t_Printf *print_f, char *str)
{
	if (print_f->precision < 0)
		print_f->result += ft_putstr(str, print_f->precision);
	else
	{
		if (print_f->precision == 0)
			print_f->precision = ft_strlen(str);
		print_f->result += ft_putstr(str, print_f->precision);
	}
}

void	write_precision_diu(t_Printf *print_f, int i)
{
	if (print_f->precision < 0)
		print_f->result += 0;
	if (print_f->precision == 0)
	{
		if (print_f->flags == 2)
		{
			print_f->result += ft_putstr(ft_itoa(i), ft_strlen(ft_itoa(i)));
			if (print_f->width > print_f->precision)
				spaces_type_width(print_f, ft_size_num(i));
		}
		else
		{
			if (print_f->flags == 1 )
			{
				if (i < 0)
				{
					print_f->result += ft_putchar('-');
					i = ft_abs(i);
				}
				zero_type_width(print_f, ft_size_num(i) + 1);
			}
			print_f->result += ft_putstr(ft_itoa(i), ft_strlen(ft_itoa(i)));
		}
	}
	else if (print_f->precision > 0)
	{
		if (print_f->width == print_f->precision)
		{
			if (print_f->precision > ft_size_num(i))
			{
				zero_type_width(print_f, ft_size_num(i));
				print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
			}
			if (ft_size_num(i) > print_f->precision)
				print_f->result += ft_putstr(ft_itoa(i), print_f->precision);
		}
		else if (print_f->width < print_f->precision)
		{
			print_f->width = print_f->precision;
			if (print_f->precision > ft_size_num(i))
			{
				zero_type_width(print_f, ft_size_num(i));
				print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
			}
			if (ft_size_num(i) > print_f->precision)
				print_f->result += ft_putstr(ft_itoa(i), print_f->precision);
		}
		else if (print_f->width > print_f->precision)
		{
			if (print_f->flags == 2)
			{
					spaces_type_width(print_f, print_f->precision + ft_size_num(i) + 1);
				if (print_f->precision == ft_size_num(i))
				{
					print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
					spaces_type_width(print_f, print_f->precision);
				}
				if (print_f->precision > ft_size_num(i))
				{
					print_f->width = print_f->precision;
					zero_type_width(print_f, ft_size_num(i));
					print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
					spaces_type_width(print_f, print_f->precision - ft_size_num(i));
				}
				if (ft_size_num(i) > print_f->precision)
				{
					print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
					spaces_type_width(print_f, ft_size_num(i));
				}
			}
			else if (print_f->flags != 2)
			{
				if (i < 0)
				{
					spaces_type_width(print_f, print_f->precision + 1);
					print_f->result += ft_putchar('-');
					i = ft_abs(i);
				}
				else
					spaces_type_width(print_f, print_f->precision);
				if (print_f->precision == ft_size_num(i))
					print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
				if (print_f->precision > ft_size_num(i))
				{
					print_f->width = print_f->precision;
					zero_type_width(print_f, ft_size_num(i));
					print_f->result += ft_putstr(ft_itoa(i), ft_size_num(i));
					spaces_type_width(print_f, print_f->precision + ft_size_num(i));
				}
				if (ft_size_num(i) > print_f->precision)
					print_f->result += ft_putstr(ft_itoa(i), print_f->precision);
			}
			
		}
	}
}
