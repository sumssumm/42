/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:35:13 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/24 06:38:24 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*top1;
	t_node	*top2;
	t_node	*last;

	top1 = stack_a->head->next;
	top2 = top1->next;
	last = stack_a->tail->prev;
	if (top1 != stack_a->tail && top2 != stack_a->tail)
	{
		stack_a->head->next = top2;
		top2->prev = stack_a->head;
		last->next = top1;
		top1->prev = last;
		top1->next = stack_a->tail;
		stack_a->tail->prev = top1;
	}
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*top1;
	t_node	*top2;
	t_node	*last;

	top1 = stack_b->head->next;
	top2 = top1->next;
	last = stack_b->tail->prev;
	if (top1 != stack_b->tail && top2 != stack_b->tail)
	{
		stack_b->head->next = top2;
		top2->prev = stack_b->head;
		last->next = top1;
		top1->prev = last;
		top1->next = stack_b->tail;
		stack_b->tail->prev = top1;
	}
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
