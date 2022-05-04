/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:13:03 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/03 21:26:59 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	words_cnt(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			cnt++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	return (cnt);
}

char	*ft_malloc(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_charset(str[i], charset))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_charset(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tmp;
	int		i;
	int		size;

	i = 0;
	size = words_cnt(str, charset);
	tmp = malloc(sizeof(char *) * (size + 1));
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			tmp[i] = ft_malloc(str, charset);
			while (*str && !is_charset(*str, charset))
				str++;
			i++;
		}
	}
	tmp[i] = NULL;
	return (tmp);
}
