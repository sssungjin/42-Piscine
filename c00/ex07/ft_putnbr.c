/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:25:30 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/23 15:11:49 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar2('-');
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			nb %= 10;
		}
		if (nb < 10)
			ft_putchar2(nb + '0');
	}
}
