/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:34:28 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/07 11:08:18 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		define_fmt_itoa(char type, va_list args)
{
	char	*str;
	size_t	len;

	if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(args, int));
	if (type == 'u')
		str = ft_itoa(va_arg(args, unsigned int));
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t		define_fmt_sc(char type, va_list args)
{
	size_t	len;

	if (type == 'c')
		len = ft_putchar(va_arg(args, int));
	if (type == 's')
		len = ft_putstr(va_arg(args, char *));
	return (len);
}

size_t		define_fmt_pxX(char type, va_list args)
{
	size_t	len;
	char	*base;
	char	*base_maj;

	base = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	if (type == 'p')
		len = ft_putstr("0x") + ft_putstr(ft_itoa_base(va_arg(args, long), base));
	if (type == 'x')
		len = ft_putstr(ft_itoa_base(va_arg(args, int), base));
	if (type == 'X')
		len = ft_putstr(ft_itoa_base(va_arg(args, int), base_maj));
	return (len);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		args;
	char		type;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
			i++;
		}
		else if (fmt[i] == '%')
		{
			while (fmt[i + 1] == ' ')
				fmt++;
			type = fmt[i + 1];
			if (type == 'c' || type == 's')
				len += define_fmt_sc(type, args);
			if (type == 'd' || type == 'u' || type == 'i')
				len += define_fmt_itoa(type, args);
			if (type == 'p' || type == 'x' || type == 'X')
				len += define_fmt_pxX(type, args);
			if (type == '%')
				len += ft_putchar('%');
			fmt += 2;
		}
	}
	va_end(args);
	return (len + i);
}

int		main(void)
{
	char	*str;
	int		test;
	char	char1;
	char	char2;
	unsigned int	hex;

	test = 1234;
	hex = 2147483647;
	str = "Tanguy";
	char1 = 'O';
	char2 = 'K';

	ft_printf(" %d", ft_printf("COUCOU %s %d %c-%c %p %x %X", str, test, char1, char2, str, hex, hex));
	printf("\n");
	printf(" %d", printf("COUCOU %s %d %c-%c %p %x %X", str, test, char1, char2, str, hex, hex));
	return (0);
}
