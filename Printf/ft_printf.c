/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:28 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 13:00:12 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*initialize_struct(void)
{
	t_printf	*new_struct;

	if (!(new_struct = malloc(sizeof(t_printf))))
		return (0);
	new_struct->type = '\0';
	new_struct->flags = 0;
	new_struct->width = 0;
	new_struct->neg = 0;
	new_struct->precision = 0;
	new_struct->result = 0;
	return (new_struct);
}

t_printf	*reset_struct(t_printf *struct_name)
{
	struct_name->type = '\0';
	struct_name->flags = 0;
	struct_name->width = 0;
	struct_name->neg = 0;
	struct_name->precision = 0;
	struct_name->result = struct_name->result;
	return (struct_name);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	t_printf		*print_f;
	int				i;
	int				len;

	if (!(print_f = initialize_struct()))
		return (-1);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += parse(format + i + 1, print_f, args);
			ft_bzero(print_f, sizeof(print_f));
			print_f = reset_struct(print_f);
		}
		else
			print_f->result += ft_putchar(format[i]);
		i++;
	}
	len = print_f->result;
	free(print_f);
	va_end(args);
	return (len);
}
