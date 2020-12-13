/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:24:36 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/13 15:39:43 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libftprintf/libft.h"
# include <stdio.h>

typedef struct	s_Printf
{
	char type; /* cspduixX% */
	int	 flags; /* Flags "0->1" "- ->2" "+ ->3"*/
	int	 width; /* number * => sets the minimum field width for an output value */
	int	 precision; /* .number .* => max number of caracter to print (or minimum number fo interger digits) */
	int  star;
	int	 result; /* Will be the result of the printf function (integer that represent the lenght of the printed chars) */
}				t_Printf;

int				ft_printf(const char *format, ...);
t_Printf		*initialize_struct(void);
t_Printf		*reset_struct(t_Printf *struct_name);

int				regular_types(char c);
int				parse_format(const char *format, t_Printf *print_f, va_list args);

/*--- Arguments controller ---*/
void			define_convert_args(t_Printf *print_f, va_list args, char type);
void			convert_cs(t_Printf *print_f, va_list args);
void			convert_num(t_Printf *print_f, va_list args);
void			convert_pxx(t_Printf *print_f, va_list args);
void			convert_percent(t_Printf *print_f, va_list args);

/*----- Width controller -----*/
int				add_width(t_Printf *print_f, const char *format);
int				add_star_width(t_Printf *print_f);
void			star_condition(t_Printf *print_f, va_list args);
void			spaces_type_width(t_Printf *print_f, int len);
void			zero_type_width(t_Printf *print_f, int len);
void			write_width_c(t_Printf *print_f);
void			write_width_str(t_Printf *print_f, char *str);
void			write_width_num(t_Printf *print_f, int num);

/*---- Justify controller ---*/
int				justify(t_Printf *print_f, const char *pad);
void			str_pad_width(t_Printf *print_f, char *str);
void			num_pad_width(t_Printf *print_f, int i);

/*--- Precision controller --*/
int				set_precision(t_Printf *print_f, const char *prec);
void			write_precision(t_Printf *print_f, char *str);
void			write_precision_diu(t_Printf *print_f, int i);

#endif
