/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbillon <tbillon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:25:34 by tbillon           #+#    #+#             */
/*   Updated: 2020/11/28 12:44:51 by tbillon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_sep(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

int		count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (is_sep(*str, c) && i > 0)
		{
			count++;
			i = 0;
		}
		else if (!is_sep(*str, c))
			i++;
		str++;
	}
	if (i > 0)
		count++;
	return (count);
}

int		word_len(char *str, char end)
{
	int	i;

	i = 0;
	while (str[i] != end && str[i])
		i++;
	return (i);
}

char	*set_word(char *str, char sep)
{
	int		i;
	int		size_w;
	char	*word;

	i = 0;
	size_w = word_len(str, sep);
	if (!(word = malloc(sizeof(char) * (size_w + 1))))
		return (0);
	while (i < size_w && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		nb_words;

	if (!s)
		return (0);
	str = (char *)s;
	nb_words = count_words(str, c);
	if (!(tab = malloc(sizeof(char *) * (nb_words + 1))))
		return (0);
	i = 0;
	while (i < nb_words && *str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
		{
			tab[i] = set_word(str, c);
			str = str + word_len(str, c);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
