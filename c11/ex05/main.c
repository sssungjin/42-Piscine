/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungcho <sungcho@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:24:07 by sungcho           #+#    #+#             */
/*   Updated: 2022/05/05 16:10:06 by sungcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	op_index(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (-1);
}

int	do_op(int a, int b, char c)
{
	int	(*cal[5])(int, int);
	int	op;

	op = op_index(c);
	cal[0] = ft_plus;
	cal[1] = ft_minus;
	cal[2] = ft_mul;
	cal[3] = ft_div;
	cal[4] = ft_mod;
	if (op == 3 && b == 0)
		return (-1);
	if (op == 4 && b == 0)
		return (-2);
	return (cal[op](a, b));
}

int	is_operator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		value[2];
	int		result;
	char	op;

	op = argv[2][0];
	if ((!is_operator(op) || ft_strlen(argv[2]) != 1) && argc == 4)
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argc == 4)
	{
		value[0] = ft_atoi(argv[1]);
		value[1] = ft_atoi(argv[3]);
		result = do_op(value[0], value[1], op);
		if (op_index(op) == 3 && value[1] == 0 && result == -1)
			write(1, "Stop : division by zero", 23);
		else if (op_index(op) == 4 && value[1] == 0 && result == -2)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(result);
		write(1, "\n", 1);
	}
	return (0);
}
