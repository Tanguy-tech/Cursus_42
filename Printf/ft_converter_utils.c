/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 08:46:12 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/21 11:24:54 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_pad_width(t_Printf *print_f, char *str)
{
	if (print_f->type == 'p')
	{
		str = ft_strjoin("0x", str);
		if (print_f->flags == 2)
			write_precision_str(print_f, str);
		if (print_f->width >= 0)
		{
			write_width_str(print_f, str);
			if (print_f->flags != 2)
				write_precision_str(print_f, str);
		}
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

void	num_pad_width(t_Printf *print_f, long i)
{
	int		neg;
	char	*str;
	int		j;

	neg = 0;
	if (print_f->precision > print_f->width)
		j = print_f->precision;
	else
		j = print_f->width;
	str = calloc(sizeof(char), j + 1);
	if (i < 0)
	{
		if (i != -2147483648)
		{
			i = ft_abs(i);
			neg = 1;
			str = ft_strjoin_c('-', str);
		}
	}
	if ((j = print_f->precision) > 0 || (print_f->flags == 1 && print_f->precision == 0))
	{
		if (print_f->flags == 1 && print_f->precision <= 0)
		{
			if (neg == 1)
				j = print_f->width - 1;
			else
				j = print_f->width;
		}
		while (j - ft_strlen(ft_itoa(i)) > 0)
		{
			str = ft_strjoin_c('0', str);
			j--;
		}
		str = ft_strjoin(str, ft_itoa(i));
	}
	else
	{
		if (print_f->precision < 0 && i == 0)
		{
			if (print_f->width > 0)
				str = ft_strjoin(str, " ");
			else
				str = ft_strjoin(str, NULL);
		}
		else
			str = ft_strjoin(str, ft_itoa(i));
	}
	if ((j = print_f->width) > 0 && print_f->width > print_f->precision)
	{
		if (print_f->precision > 0 && print_f->precision > ft_strlen(ft_itoa(i)))
			j -= print_f->precision;
		else
			j -= ft_strlen(ft_itoa(i));
		if (neg == 1)
			j -= 1;
		if (print_f->flags == 2)
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
		}
		else if (print_f->flags != 1 || (print_f->flags == 1 && print_f->width > print_f->precision && print_f->precision > 0))
		{
			while (j > 0)
			{
				str = ft_strjoin_left(' ', str);
				j--;
			}
		}
		else if (print_f->flags == 1 && print_f->precision < 0 && print_f->width > print_f->precision)
		{
			if (str == NULL)
			{
				str = "\0";
				j += 1;
			}
			while (j > 0)
			{
				str = ft_strjoin_left(' ', str);
				j--;
			}
		}
	}
	print_f->result += ft_putstr(str, ft_strlen(str));
	free(str);
}

void	hexa_pad_width(t_Printf *print_f, char *hexa)
{
	char	*str;
	int		j;

	if (print_f->type == 'x' || print_f->type == 'X')
	{
		if (print_f->precision > print_f->width)
			j = print_f->precision;
		else
			j = print_f->width;
		str = calloc(sizeof(char), j + 1);
		if ((j = print_f->precision) > 0 || (print_f->flags == 1 && print_f->precision == 0))
		{
			if (print_f->flags == 1 && print_f->precision <= 0)
				j = print_f->width;
			while (j - ft_strlen(hexa) > 0)
			{
				str = ft_strjoin_left('0', str);
				j--;
			}
			str = ft_strjoin(str, hexa);
		}
		else
		{
			if (print_f->precision < 0 && ft_strcmp(hexa, "0") == 0)
			{
				if (print_f->width > 0)
					str = ft_strjoin(str, " ");
				else
					str = ft_strjoin(str, NULL);
			}
			else
				str = ft_strjoin(str, hexa);
		}
		if ((j = print_f->width) > 0 && print_f->width > print_f->precision)
		{
			if (print_f->precision > 0 && print_f->precision > ft_strlen(hexa))
				j -= print_f->precision;
			else
				j -= ft_strlen(hexa);
			if (print_f->flags == 2)
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
			}
			else if (print_f->flags != 1 || (print_f->flags == 1 && print_f->width > print_f->precision && print_f->precision > 0))
			{
				while (j > 0)
				{
					str = ft_strjoin_left(' ', str);
					j--;
				}
			}
			else if (print_f->flags == 1 && print_f->precision < 0 && print_f->width > print_f->precision)
			{
				if (str == NULL)
				{
					str = "\0";
					j += 1;
				}
				while (j > 0)
				{
					str = ft_strjoin_left(' ', str);
					j--;
				}
			}
		}
		print_f->result += ft_putstr(str, ft_strlen(str));
		free(str);
	}
}

void	star_condition(t_Printf *print_f)
{
	if (print_f->width < 0)
	{
		print_f->width = ft_abs(print_f->width);
		print_f->flags = 2;
	}
}
