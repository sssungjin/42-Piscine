/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:52:46 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/02 20:08:22 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	nbr_size(int nbr, int base_len)
{
	int			size;
	long long	num;

	num = nbr;
	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	while (num > 0)
	{
		num /= base_len;
		size++;
	}
	return (size);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char		*temp;
	long long	num;
	int			size;

	num = nbr;
	size = nbr_size(num, ft_strlen(base));
	temp = malloc(sizeof(char) * (size + 1));
	temp[size] = '\0';
	if (num == 0)
		temp[0] = base[0];
	if (num < 0)
	{
		temp[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		temp[--size] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
	}
	return (temp);
}
