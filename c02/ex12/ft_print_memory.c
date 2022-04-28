/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:08:19 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/28 13:30:18 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long long addr, unsigned int cnt)
{
	if (addr != 0)
	{
		print_addr(addr / 16, cnt + 1);
		write(1, &"0123456789abcdef"[addr % 16], 1);
	}
	else
	{
		while (cnt < 16)
		{
			write(1, "0", 1);
			cnt++;
		}
	}
}

void	print_hexa(unsigned char *str, unsigned int len)
{	
	unsigned int	i;

	i = 0;
	write(1, ":", 1);
	while (i < len)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[str[i] / 16], 1);
		write(1, &"0123456789abcdef"[str[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		i++;
	}
}

void	print_str(char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	write(1, " ", 1);
	while (i < len)
	{
		if (str[i] <= 31 || str[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (size > 0)
	{
		if (size > 16)
			j = 16;
		else
			j = size;
		print_addr((unsigned long long)addr + i, 0);
		print_hexa((unsigned char *)addr + i, j);
		print_str((char *)addr + i, j);
		i += j;
		size -= j;
	}
	return (addr);
}
