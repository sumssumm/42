/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:28 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/11 21:53:44 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks --list push_swap");
}

void printStack(t_stack *stack) {
    t_node *current = stack->head->next;
    while (current != stack->tail) {
        ft_printf("%d ", current->data);
        current = current->next;
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
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
		i--;
	}
  	ft_printf("Stack A: ");
    printStack(stack_a);

	atexit(check_leaks);

    return 0;
}