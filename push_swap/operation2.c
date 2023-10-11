/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:35:13 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/11 23:10:32 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*top1;
	t_node	*top2;

	top1 = stack->head->next;
	top2 = stack->head->next->next;
	if (top1 != stack->tail && top2 != stack->tail)
	{
		stack->head->next = top2;
		top2->prev = stack->head;
		top1->next = stack->tail;
		stack->tail->prev = top1;
		top2->next = top1;
		top1->prev = top2;
	}
}