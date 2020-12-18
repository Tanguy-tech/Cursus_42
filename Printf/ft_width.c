/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:16:26 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/18 10:41:08 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width(t_Printf *print_f, va_list args, const char *format)
{
	char	*str;
	int		arg;
	int		i;

	i = 0;
	if (format[i] == '*')
	{
		arg = va_arg(args, int);
		if (arg < 0)
		{
			arg = ft_abs(arg);
			print_f->flags = 2;
		}
		print_f->width = arg;
		return (i + 1);
	}
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
	print_f->width = ft_atoi(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
