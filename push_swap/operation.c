/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:19:49 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/11 22:48:36 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*top;
	int		top1;
	int		top2;

	top = stack->head->next;
	if (top != stack->tail && top != stack->tail)
	{
		top1 = top->data;
		top2 = top->next->data;
		top->data = top2;
		top->next->data = top1;
	}
}

void	sb(t_stack *stack)
{
	t_node	*top;
	int		top1;
	int		top2;

	top = stack->head->next;
	if (top != stack->tail && top != stack->tail)
	{
		top1 = top->data;
		top2 = top->next->data;
		top->data = top2;
		top->next->data = top1;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_b->head->next != stack_b->tail)
	{
		data = pop(stack_b);
		push(stack_a, data);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a->head->next != stack_a->tail)
	{
		data = pop(stack_a);
		push(stack_b, data);
	}
}