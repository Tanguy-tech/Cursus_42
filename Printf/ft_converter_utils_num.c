/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils_num.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:31:14 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 13:00:41 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*num_first_join(t_printf *print_f, int j, char *str, char *it)
{
	if (print_f->flags == 1 && print_f->precision <= 0)
	{
		if (print_f->neg == 1)
			j = print_f->width - 1;
		else
			j = print_f->width;
	}
	while (j - ft_strlen(it) > 0)
	{
		if (!(str = ft_strjoin_c('0', str)))
			return (NULL);
		j--;
	}
	if (!(str = ft_strjoin(str, it)))
		return (NULL);
	return (str);
}

char	*num_sec_join(t_printf *print_f, long i, char *str, char *it)
{
	if (print_f->precision < 0 && i == 0)
	{
		if (print_f->width > 0)
			if (!(str = ft_strjoin(str, " ")))
				return (NULL);
	}
	else
	{
		if (!(str = ft_strjoin(str, it)))
			return (NULL);
	}
	return (str);
}

char	*num_last_step(t_printf *print_f, char *it, int j, char *str)
{
	if (print_f->precision > 0 && print_f->precision > ft_strlen(it))
		j -= print_f->precision;
	else
		j -= ft_strlen(it);
	if (print_f->neg == 1)
		j -= 1;
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

char	*create_str_left(t_printf *print_f, int j, char *str)
{
	if (print_f->flags != 1 || (print_f->flags == 1
		&& print_f->width > print_f->precision && print_f->precision > 0))
	{
		while (0 < j--)
			if (!(str = ft_strjoin_left(' ', str)))
				return (NULL);
	}
	else if (print_f->flags == 1 && print_f->precision < 0
		&& print_f->width > print_f->precision)
	{
		if (str == NULL)
		{
			str = "\0";
			j += 1;
		}
		while (0 < j--)
			if (!(str = ft_strjoin_left(' ', str)))
				return (NULL);
	}
	return (str);
}
