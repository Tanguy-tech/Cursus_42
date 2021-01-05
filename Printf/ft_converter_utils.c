/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:46:12 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 13:06:30 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pad_width(t_printf *print_f, char *str)
{
	if (print_f->type == 'p')
	{
		str = ft_strjoin_p("0x", str);
		if (print_f->flags == 2)
			write_precision_str(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision_str(print_f, str);
		}
		free(str);
	}
	else
	{
		if (print_f->flags == 2)
			write_precision_str(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision_str(print_f, str);
		}
	}
}

void	num_pad_width(t_printf *print_f, long i)
{
	char	*str;
	int		j;
	char	*it;

	str = init_str(print_f);
	if (i < 0)
	{
		if (i != -2147483648)
		{
			i = ft_abs(i);
			print_f->neg = 1;
			str = ft_strjoin_c('-', str);
		}
	}
	it = ft_itoa(i);
	if ((j = print_f->precision) > 0 ||
		(print_f->flags == 1 && print_f->precision == 0))
		str = num_first_join(print_f, j, str, it);
	else
		str = num_sec_join(print_f, i, str, it);
	if ((j = print_f->width) > 0 && print_f->width > print_f->precision)
		str = num_last_step(print_f, it, j, str);
	print_f->result += ft_putstr(str, ft_strlen(str));
	free(str);
	free(it);
}

void	hexa_pad_width(t_printf *print_f, char *hexa)
{
	char	*str;
	int		j;

	if (print_f->precision > print_f->width)
		j = print_f->precision;
	else
		j = print_f->width;
	str = ft_calloc(sizeof(char), j + 1);
	if ((j = print_f->precision) > 0 ||
		(print_f->flags == 1 && print_f->precision == 0))
		str = hex_first_join(print_f, j, hexa, str);
	else
		str = hex_sec_join(print_f, hexa, str);
	if ((j = print_f->width) > 0 && print_f->width > print_f->precision)
		str = hex_last_step(print_f, hexa, j, str);
	print_f->result += ft_putstr(str, ft_strlen(str));
	free(str);
}

char	*pad_left(char *str, int j)
{
	if (str == NULL)
	{
		str = "\0";
		j += 1;
	}
	while (j > 0)
	{
		str = ft_strjoin_c(' ', str);
		j--;
	}
	return (str);
}

char	*init_str(t_printf *print_f)
{
	int		j;
	char	*str;

	if (print_f->precision > print_f->width)
		j = print_f->precision;
	else
		j = print_f->width;
	str = ft_calloc(sizeof(char), j + 1);
	return (str);
}
