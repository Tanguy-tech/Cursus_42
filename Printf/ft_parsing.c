/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 08:18:26 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 13:09:20 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		regular_types(char c)
{
	int		i;
	char	*types;

	types = "cspdiuxX%";
	i = 0;
	while (types[i])
	{
		if (types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		parse(const char *format, t_printf *print_f, va_list args)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '-' || format[i] == '0')
			i += justify(print_f, format + i);
		if (ft_isdigit(format[i]) == 1 || format[i] == '*')
			i += add_width(print_f, args, format + i);
		if (format[i] == '.')
			i += set_prec(print_f, args, format + i + 1);
		if (regular_types(format[i]) == 1)
		{
			print_f->type = format[i];
			define_convert_args(print_f, args, print_f->type);
			return (i + 1);
		}
		i++;
	}
	return (i);
}
