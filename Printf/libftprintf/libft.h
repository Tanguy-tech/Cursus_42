/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:29:30 by tbillon           #+#    #+#             */
/*   Updated: 2020/12/09 13:15:16 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>


int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_itoa(int n);
char	*ft_itoa_base(long int n, char *base);
int		ft_atoi(char *str);
int		ft_size_num(int x);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_isdigit(int c);

#endif
