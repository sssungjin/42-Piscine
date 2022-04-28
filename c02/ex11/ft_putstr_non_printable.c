/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:57:52 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/27 20:07:39 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexa(int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &hex[n / 16], 1);
	write(1, &hex[n % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 0)
		{
			c = str[i];
			print_hexa(c);
		}
		else if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
			print_hexa(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
