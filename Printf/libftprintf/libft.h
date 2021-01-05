/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:29:30 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/22 11:02:36 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_putchar(char c);
int		ft_putstr(char *str, int prec);
char	*ft_itoa(long n);
char	*ft_itoa_base(unsigned long n, char *base);
int		ft_atoi(char *str);
int		ft_size_num(int x);
int		ft_size_num_base(unsigned long n, int base);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_p(char *s1, char *s2);
char	*ft_strjoin_c(char c, char *str);
char	*ft_strjoin_left(char c, char *str);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_abs(int n);
void	ft_bzero(void *s, int n);
int		ft_strcmp(char *s1, char *s2);
void	*ft_calloc(size_t count, int size);

#endif
