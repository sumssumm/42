/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:44:05 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/31 17:13:43 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_ra_rra(t_stack *stack_a, int *pos)
{
	while (*pos)
	{
		if (*pos > 0)
		{
			ra(stack_a);
			*pos -= 1;
		}
		else
		{
			rra(stack_a);
			*pos += 1;
		}
	}
}

void	final_sort(t_stack *stack_a)
{
	int		a_min;
	int		pos;
	t_node	*node;

	node = stack_a->head->next;
	find_min_max(stack_a, &a_min, &pos);
	pos = 0;
	while (stack_a->head->next != stack_a->tail)
	{
		if (node->data == a_min)
			break ;
		pos++;
		node = node->next;
	}
	if (pos > stack_size(stack_a) / 2)
		pos = pos - stack_size(stack_a);
	pos_ra_rra(stack_a, &pos);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	push_to_b(stack_a, stack_b);
	while (stack_size(stack_a) > 3)
		pb(stack_a, stack_b);
	if (stack_size(stack_a) == 3)
		sort_three(stack_a);
	if (stack_size(stack_a) == 2)
		sort_two(stack_a);
	sort_stack_b(stack_a, stack_b);
	final_sort(stack_a);
}
