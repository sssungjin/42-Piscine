/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:57:06 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/05 17:20:17 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*map;
	int	i;

	map = malloc(sizeof(int) * length);
	if (!map)
		return (NULL);
	i = 0;
	while (i < length)
	{
		map[i] = f(tab[i]);
		i++;
	}
	return (map);
}
