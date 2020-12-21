/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:37:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/21 13:26:43 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision(t_Printf *print_f, va_list args, const char *prec)
{
	int		i;
	int		arg;
	int		res;

	i = 0;
	if (prec[i] == '*')
	{
		arg = va_arg(args, int);
		if (arg < 0)
			arg = 0;
		else if (arg == 0)
			arg = -1;
		print_f->precision = arg;
		return (i + 1);
	}
	else if (ft_isdigit(prec[i]) == 1)
	{
		res = ft_atoi((char *)&prec[i]);
		if (res == 0)
		{
			print_f->precision = -1;
			return (1);
		}
		else
			print_f->precision = res;
		while (ft_isdigit(prec[i]) == 1)
			i++;
	}
	else
		print_f->precision = -1;
	return (i);
}

void	write_precision_str(t_Printf *print_f, char *str)
{
	if (print_f->precision < 0)
	{
		print_f->result += ft_putstr(str, print_f->precision);
	}
	else
	{
		if (print_f->precision == 0)
			print_f->precision = ft_strlen(str);
		print_f->result += ft_putstr(str, print_f->precision);
	}
}
