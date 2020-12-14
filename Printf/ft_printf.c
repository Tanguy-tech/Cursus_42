/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:28 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/14 17:25:41 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_Printf	*initialize_struct(void)
{
	t_Printf	*new_struct;

	if (!(new_struct = malloc(sizeof(t_Printf))))
		return (0);
	new_struct->type = '\0';
	new_struct->flags = 0;
	new_struct->width = 0;
	new_struct->star = 0;
	new_struct->precision = 0;
	new_struct->result = 0;
	return (new_struct);
}

t_Printf	*reset_struct(t_Printf *struct_name)
{
	struct_name->type = '\0';
	struct_name->flags = 0;
	struct_name->width = 0;
	struct_name->star = 0;
	struct_name->precision = 0;
	struct_name->result = struct_name->result;
	return (struct_name);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	t_Printf		*print_f;
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
			i += parse_format(format + i + 1, print_f, args);
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

// int			main(void)
// {
// 	char			*str;
// 	int				test;
// 	char			char1;
// 	char			char2;
// 	unsigned int	hex;

// 	test = 123456789;
// 	hex = 2147483647;
// 	str = "Tanguy";
// 	char1 = 'O';
// 	char2 = 'K';
// 	ft_printf(" |%d", ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011));
// 	printf("\n");
// 	printf(" |%d", printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011));
// 	return (0);
// }
