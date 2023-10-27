#include "push_swap.h"

void	get_pivot(int size, int *num_arr, t_stack *stack)
{
	stack->p1 = num_arr[size / 3];
	stack->p2 = num_arr[size * 2 / 3];
	printf("\n p: %d %d \n", stack->p1, stack->p2);
}


void	print_error(int	error)
{
	if (error == -1)
		ft_printf("Error\n");
	exit(1);
}

long	ps_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			print_error(-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= sign;
	if (result > 2147483647 || result < -2147483648)
		print_error(-1);
	return ((int)result);
}