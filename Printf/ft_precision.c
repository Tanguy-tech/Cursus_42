/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:37:18 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/16 15:20:14 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_precision(t_Printf *print_f, va_list args, const char *prec)
{
	int		i;
	int		arg;
	char	*str_precision;

	i = 0;
	if (prec[i] == '*')
	{
		arg = va_arg(args, int);
		if (arg < 0)
			arg = -1;
		print_f->precision = arg;
		return (i + 1);
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
	free(str_precision);
	i = ft_strlen(str_precision);
	return (i);
}

void	write_precision_str(t_Printf *print_f, char *str)
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

