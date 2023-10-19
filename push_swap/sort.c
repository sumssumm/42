/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:01:45 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/20 04:47:49 by suminpar         ###   ########.fr       */
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
	int		a;
	int		b;
	int		c;

	a = stack_a->head->next->data;
	b = stack_a->head->next->next->data;
	c = stack_a->head->next->next->next->data;
	if (a > b && a > c)
	{
		ra(stack_a);
		if (b < c)
			sa(stack_a);
	}
	else if (b > a && b > c)
	{
		if (a < c)
			sa(stack_a);
	}
	else if (c > a && c > b)
	{
		rra(stack_a);
		if (a < b)
			sa(stack_a);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	count;

	count = 0;
	while (stack_a->size > 2)
	{
		min = find_min(stack_a, &max);
		if (min == stack_a->head->next->data)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		count++;
	}
	sort_three(stack_a);
	while (count > 0)
	{
		rra(stack_a);
		count--;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

int	find_min(t_stack *stack, int *max)
{
	int	min;
	t_node *node;

	min = stack->tail->prev->data;
	*max = stack->head->next->data;
	node = stack->head->next;
	while (node != stack->tail)
	{
		if (node->data < min)
			min = node->data;
		if (node->data > *max)
			*max = node->data;
		node = node->next;
	}
	return (min);
}

