/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:29:31 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/23 15:52:13 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec(char *arr, int n, int i, int size)
{
	if (size == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
		{
			write(1, ", ", 2);
			return ;
		}
	}
	while (i <= 9)
	{
		arr[size] = i + '0';
		rec(arr, n, i + 1, size + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	if (n > 0 && n < 10)
		rec(arr, n, 0, 0);
}
