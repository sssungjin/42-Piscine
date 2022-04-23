/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:49:56 by sungcho           #+#    #+#             */
/*   Updated: 2022/04/16 16:49:58 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush_print(int x, const char *alphabets)
{
	int	len;

	if (x > 2)
		len = x - 2;
	else
		len = 0;
	if (x > 0)
		ft_putchar(alphabets[0]);
	while (len--)
		ft_putchar(alphabets[1]);
	if (x > 1)
		ft_putchar(alphabets[2]);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	middle_lines;

	if (y > 2)
		middle_lines = y - 2;
	else
		middle_lines = 0;
	if (y > 0)
		rush_print(x, "ABC");
	while (middle_lines--)
		rush_print(x, "B B");
	if (y > 1)
		rush_print(x, "ABC");
}
