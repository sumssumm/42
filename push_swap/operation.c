/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:19:49 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 18:46:14 by suminpar         ###   ########.fr       */
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
	write(1, "sa\n", 3);
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
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_b->head->next != stack_b->tail)
	{
		data = pop(stack_b);
		push(stack_a, data);
		ft_printf("pa\n");
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a->head->next != stack_a->tail)
	{
		data = pop(stack_a);
		push(stack_b, data);
		ft_printf("pb\n");
	}
}
