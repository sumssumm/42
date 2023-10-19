/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:28 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/20 01:37:53 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks --list push_swap");
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		data;

	if (argc < 2)
		return (-1);
	if (init_stack(&stack_a) < 0 || init_stack(&stack_b) < 0)
		return (-1);
	i = argc - 1;
	while (i > 0)
	{
		data = ft_atoi(argv[i]);
		push(stack_a, data);
		stack_a->size++;
		i--;
	}
	sort_five(stack_a, stack_b);
	ft_printf("Stack A: ");
	print_stack(stack_a);
	ft_printf("Stack B: ");
	print_stack(stack_b);
	ft_printf("a : %d b : %d\n", stack_a->size, stack_b->size);
	atexit(check_leaks);
	return (0);
}
