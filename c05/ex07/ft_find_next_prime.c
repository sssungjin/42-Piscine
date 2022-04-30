/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:21:11 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/30 14:51:52 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(int nb)
{
	long long	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 1;
	while (1)
	{
		if (ft_is_prime1(nb) == 1)
			return (nb);
		nb += 1;
	}
}
