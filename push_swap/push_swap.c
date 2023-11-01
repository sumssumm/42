/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:28 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 18:51:11 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argv(int argc, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				flag = 1;
			j++;
		}
		if (flag == 0)
			print_error();
		i++;
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) == 2)
		sort_two(stack_a);
	else if (stack_size(stack_a) == 3)
		sort_three(stack_a);
	else if (stack_size(stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_size(stack_a) > 5)
		sort_big(stack_a, stack_b);
}

void	av_to_stack(int argc, char **argv, t_stack *stack, int *arr)
{
	int		i;
	int		data;

	i = argc - 1;
	while (i >= 0)
	{
		data = ps_atoi(argv[i]);
		arr[i] = data;
		push(stack, data);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*num_arr;
	char	**str_split;
	int		size;

	if (argc < 2)
		return (0);
	check_argv(argc, argv);
	init_stack(&stack_a);
	init_stack(&stack_b);
	str_split = split_argv(join_argv(argc, argv), &size);
	if (str_split == NULL)
		return (-1);
	check_errors(size, str_split);
	num_arr = (int *)malloc(sizeof(int) * (size));
	if (num_arr == NULL)
		return (-1);
	av_to_stack(size, str_split, stack_a, num_arr);
	ft_sort_int_tab(num_arr, size, stack_a);
	if (check_asceding(stack_a) == -1)
		ft_sort(stack_a, stack_b);
	split_free(str_split);
	all_stack_free(stack_a, stack_b);
	return (0);
}
