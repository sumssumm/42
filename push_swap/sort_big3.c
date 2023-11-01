/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:12:45 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/31 17:13:33 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	excute_rr_rrr(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->a_pos > 0 && stack_b->b_pos > 0)
	{
		stack_a->a_pos--;
		stack_b->b_pos--;
		rr(stack_a, stack_b);
	}
	while (stack_a->a_pos < 0 && stack_b->b_pos < 0)
	{
		stack_a->a_pos++;
		stack_b->b_pos++;
		rrr(stack_a, stack_b);
	}
}

void	excute_ra_rra(t_stack *stack_a)
{
	while (stack_a->a_pos)
	{
		if (stack_a->a_pos > 0)
		{
			ra(stack_a);
			stack_a->a_pos--;
		}
		else
		{
			rra(stack_a);
			stack_a->a_pos++;
		}
	}
}

void	excute_rb_rrb(t_stack *stack_b)
{
	while (stack_b->b_pos)
	{
		if (stack_b->b_pos > 0)
		{
			rb(stack_b);
			stack_b->b_pos--;
		}
		else
		{
			rrb(stack_b);
			stack_b->b_pos++;
		}
	}
}
