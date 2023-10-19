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

void	sa(t_stack *stack_a)
{
	t_node	*top1;
	t_node	*top2;
	int		tmp;

	top1 = stack_a->head->next;
	top2 = top1->next;
	if (top1 != stack_a->tail && top1 != stack_a->tail)
	{
		tmp = top1->data;
		top1->data = top2->data;
		top2->data = tmp;
	}
}

void	sb(t_stack *stack_b)
{
	t_node	*top1;
	t_node	*top2;
	int		tmp;

	top1 = stack_b->head->next;
	top2 = top1->next;
	if (top1 != stack_b->tail && top1 != stack_b->tail)
	{
		tmp = top1->data;
		top1->data = top2->data;
		top2->data = tmp;
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