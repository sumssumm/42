/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:01:45 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/31 16:49:02 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	t_node	*top;

	top = stack_a->head->next;
	if (top->data > top->next->data)
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = stack_a->head->next;
	b = a->next;
	c = b->next;
	if (a->data < b->data && a->data < c->data && b->data < c->data)
		return ;
	else if (a->data > b->data && a->data > c->data && b->data > c->data)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a->data > b->data && a->data > c->data && b->data < c->data)
		ra(stack_a);
	else if (a->data < b->data && a->data < c->data && b->data > c->data)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a->data > b->data && a->data < c->data && b->data < c->data)
		sa(stack_a);
	else
		rra(stack_a);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		max;
	t_node	*node;

	node = stack_a->head->next;
	while (stack_size(stack_a) > 3)
	{
		find_min_max(stack_a, &min, &max);
		node = stack_a->head->next;
		if (node->data == max || node->data == min)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (stack_size(stack_b) > 0)
	{
		pa(stack_a, stack_b);
		node = stack_a->head->next;
		if (node->data > stack_a->tail->prev->data)
			ra(stack_a);
	}
}

void	find_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*node;

	node = stack->head->next;
	*min = node->data;
	*max = node->data;
	while (node != stack->tail)
	{
		if (node->data < *min)
			*min = node->data;
		if (node->data > *max)
			*max = node->data;
		node = node->next;
	}
}
