/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:44:15 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 18:01:40 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivot(int size, int *num_arr, t_stack *stack)
{
	stack->p1 = num_arr[size / 3];
	stack->p2 = num_arr[size * 2 / 3];
	free(num_arr);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ps_move_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

long	ps_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	i = ps_move_sign(str, &sign);
	if (!str[i])
		print_error();
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			print_error();
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		print_error();
	return ((int)result);
}
