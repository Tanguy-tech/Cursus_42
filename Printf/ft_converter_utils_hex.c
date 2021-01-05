/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:30:56 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 13:10:10 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_first_join(t_printf *print_f, int j, char *hex, char *s)
{
	if (print_f->flags == 1 && print_f->precision <= 0)
		j = print_f->width;
	while (j - ft_strlen(hex) > 0)
	{
		if (!(s = ft_strjoin_left('0', s)))
			return (NULL);
		j--;
	}
	if (!(s = ft_strjoin(s, hex)))
		return (NULL);
	return (s);
}

char	*hex_sec_join(t_printf *print_f, char *hexa, char *str)
{
	if (print_f->precision < 0 && ft_strcmp(hexa, "0") == 0)
	{
		if (print_f->width > 0)
			if (!(str = ft_strjoin(str, " ")))
				return (NULL);
	}
	else
	{
		if (!(str = ft_strjoin(str, hexa)))
			return (NULL);
	}
	return (str);
}

char	*hex_last_step(t_printf *print_f, char *hexa, int j, char *str)
{
	if (print_f->precision > 0 && print_f->precision > ft_strlen(hexa))
		j -= print_f->precision;
	else
		j -= ft_strlen(hexa);
	if (print_f->flags == 2)
	{
		if (!(str = pad_left(str, j)))
			return (NULL);
	}
	else
	{
		if (!(str = create_str_left(print_f, j, str)))
			return (NULL);
	}
	return (str);
}
