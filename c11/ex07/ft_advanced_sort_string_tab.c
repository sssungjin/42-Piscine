/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:06:56 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/04 20:20:33 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strstr2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strstr2(tab);
	while (i < size - 1)
	{
		while (j < size - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
