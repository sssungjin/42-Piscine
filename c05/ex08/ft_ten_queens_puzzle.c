/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:18:12 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/30 14:51:37 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

void	print_map(char *map)
{
	write(1, map, 10);
	write(1, "\n", 1);
}

int	promising(int i, char *map)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (map[i] == map[j] || abs(map[i] - map[j]) == abs(i - j))
			return (0);
		j++;
	}
	return (1);
}

void	backtracking(char *map, int i, char c, int *cnt)
{
	if (c <= '9')
	{
		map[i] = c;
		if (promising(i, map))
		{
			backtracking(map, i + 1, '0', cnt);
			if (i == 9)
			{
				print_map(map);
				(*cnt)++;
			}
		}
		backtracking(map, i, c + 1, cnt);
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	map[11];
	int		cnt;

	cnt = 0;
	backtracking(map, 0, '0', &cnt);
	return (cnt);
}
