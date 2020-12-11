/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:16:26 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/11 09:49:57 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width(t_Printf *print_f, const char *format)
{
	char	*str;
	int		i;

	i = 0;
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

int		add_star_width(t_Printf *print_f)
{
	print_f->width = -1;
	return (1);
}
