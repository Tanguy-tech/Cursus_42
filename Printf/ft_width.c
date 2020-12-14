/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:16:26 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/14 17:22:33 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width(t_Printf *print_f, const char *format)
{
	char	*str;
	int		i;

	i = 0;
	if (format[i] == '0' && format[i + 1] == '*')
	{
		print_f->flags = 1;
		return (1);
	}
	if (format[i] == '0' && format[i + 1] == '-')
		return (1);
	while (ft_isdigit(format[i]) == 1)
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (ft_isdigit(format[i]) == 1)
	{
		str[i] = format[i];
		i++;
	}
	str[i] = '\0';
	if (str[0] == '0' && print_f->flags == 0)
		print_f->flags = 1;
	print_f->width = ft_atoi(str);
	if (print_f->flags == 3)
		print_f->width -= 1;
	i = ft_strlen(str);
	return (i);
}

int		add_star_width(t_Printf *print_f, va_list args)
{
	print_f->width = va_arg(args, int);
	print_f->star = 1;
	return (1);
}
