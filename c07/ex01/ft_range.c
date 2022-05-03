/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:03:01 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/02 15:41:35 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	while (min < max)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
