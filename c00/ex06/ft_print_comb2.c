/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:41:45 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/23 15:11:34 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	i;

	first = 0;
	while (first <= 98)
	{
		i = first + 1;
		while (i <= 99)
		{
			ft_putchar1(first / 10 + '0');
			ft_putchar1(first % 10 + '0');
			ft_putchar1(' ');
			ft_putchar1(i / 10 + '0');
			ft_putchar1(i % 10 + '0');
			if (first == 98 && i == 99)
				return ;
			write(1, ", ", 2);
			i++;
		}
		first++;
	}
}
