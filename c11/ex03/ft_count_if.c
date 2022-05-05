/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:10:30 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/04 19:39:32 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
