/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:28 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/24 07:16:13 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks --list push_swap");
}

int ft_isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
    while (*str)
    {
        if (ft_isdigit(*(str)) == 0)
            return (-1);
        str++;
    }
    return (1);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head->next;
	while (current != stack->tail)
	{
		ft_printf("%d ", current->data);
		current = current->next;
	}
	ft_printf("\n");
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		data;
	int		*num_arr;

	if (argc < 2)
		return (-1);
	if (init_stack(&stack_a) < 0 || init_stack(&stack_b) < 0)
		print_error(-1);
	check_errors(argc, argv);
	i = argc - 1;
	while (i > 0)
	{
		data = ps_atoi(argv[i]);
		if (push(stack_a, data) < 0)
			print_error(-1);
		i--;
	}
	i = argc - 1;
	num_arr = (int *)malloc(sizeof(int) * (argc - 1));
    while (i > 0)
	{
		if (ft_isnum(argv[i]) == -1)
			print_error(-1);
		num_arr[i - 1] = ps_atoi(argv[i]);
		i--;
	}
	ft_sort_int_tab(num_arr, argc - 1);
	for(int i = 0; i < argc - 1; i++)
	{
		printf(" %d ", num_arr[i]);
	}
	get_pivot(argc - 1, num_arr, stack_a);
	if (check_asceding(stack_a) == -1)
		ft_sort(stack_a, stack_b);
	// ft_printf("Stack A: ");
	print_stack(stack_a);
	// ft_printf("Stack B: ");
	// print_stack(stack_b);
	// ft_printf("a : %d b : %d\n", stack_a->size_a, stack_b->size_b);
	// free(stack_a);
	// atexit(check_leaks);
	return (0);
}
