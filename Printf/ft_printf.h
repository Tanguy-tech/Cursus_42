/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:24:36 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 14:18:01 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libftprintf/libft.h"
# include <stdio.h>

typedef struct	s_printf
{
	char	type;
	int		flags;
	int		width;
	int		precision;
	int		neg;
	int		result;
}				t_printf;

int				ft_printf(const char *format, ...);
t_printf		*initialize_struct(void);
t_printf		*reset_struct(t_printf *struct_name);

int				regular_types(char c);
int				parse(const char *format, t_printf *print_f, va_list args);

/*
** Arguments controller
*/
void			define_convert_args(t_printf *print_f, va_list args, char type);
void			convert_cs(t_printf *print_f, va_list args);
void			convert_num(t_printf *print_f, va_list args);
void			convert_pxx(t_printf *print_f, va_list args);
void			convert_percent(t_printf *print_f);

/*
** Width controller
*/
int				add_width(t_printf *print_f, va_list args, const char *format);
void			width_is_star(t_printf *print_f, va_list args);
void			star_condition(t_printf *print_f);
void			spaces_type_width(t_printf *print_f, int len);
void			zero_type_width(t_printf *print_f, int len);
void			write_width_c(t_printf *print_f);
void			write_width_str(t_printf *print_f, char *str);

/*
** Justify controller
*/
int				justify(t_printf *print_f, const char *pad);
void			str_pad_width(t_printf *print_f, char *str);
void			num_pad_width(t_printf *print_f, long i);
void			hexa_pad_width(t_printf *print_f, char *hexa);

/*
** Precision controller
*/
int				set_prec(t_printf *print_f, va_list args, const char *prec);
void			precision_is_star(t_printf *print_f, va_list args);
void			write_precision_str(t_printf *print_f, char *str);

char			*init_str(t_printf *print_f);
char			*create_str_left(t_printf *print_f, int j, char *str);
char			*hex_first_join(t_printf *print_f, int j, char *hex, char *s);
char			*hex_sec_join(t_printf *print_f, char *hexa, char *str);
char			*hex_last_step(t_printf *print_f, char *hexa, int j, char *str);
char			*num_first_join(t_printf *print_f, int j, char *str, char *it);
char			*num_sec_join(t_printf *print_f, long i, char *str, char *it);
char			*num_last_step(t_printf *print_f, char *it, int j, char *str);
char			*pad_left(char *str, int j);

#endif
