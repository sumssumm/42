/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:06:11 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/31 17:11:06 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_pos(t_stack *stack_a, int b_data, int pos)
{
	int		a_min;
	int		a_max;
	t_node	*node;

	node = stack_a->head->next;
	find_min_max(stack_a, &a_min, &a_max);
	while (node != stack_a->tail)
	{
		if (b_data < a_min && node->data == a_min)
			break ;
		else if ((b_data > a_max && node->data == a_max) || \
				(node->next != stack_a->tail && \
				b_data > node->data && b_data < node->next->data))
		{
			pos++;
			break ;
		}
		pos++;
		node = node->next;
	}
	if (pos >= stack_size(stack_a) / 2)
		pos = pos - stack_size(stack_a);
	return (pos);
}

void	count_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int		pos;
	int		a_cnt;
	int		b_cnt;
	int		b_data;
	t_node	*b_node;

	pos = 0;
	b_node = stack_b->head->next;
	while (pos < stack_size(stack_b))
	{
		b_data = b_node->data;
		a_cnt = count_pos(stack_a, b_data, 0);
		b_cnt = pos;
		if (pos > stack_size(stack_b) / 2)
			b_cnt = pos - stack_size(stack_b);
		if (pos == 0
			|| abs(stack_a->a_pos) + abs(stack_b->b_pos) > \
			abs(a_cnt) + abs(b_cnt))
		{
			stack_a->a_pos = a_cnt;
			stack_b->b_pos = b_cnt;
		}
		b_node = b_node->next;
		pos++;
	}
}

void	ft_rotate(t_stack *stack_a, t_stack *stack_b)
{
	excute_rr_rrr(stack_a, stack_b);
	excute_ra_rra(stack_a);
	excute_rb_rrb(stack_b);
}

void	sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_size(stack_b))
	{
		stack_a->a_pos = 0;
		stack_b->b_pos = 0;
		count_rotate(stack_a, stack_b);
		ft_rotate(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		size;

	size = stack_size(stack_a);
	while (size--)
	{
		node = stack_a->head->next;
		if (stack_a->p1 > node->data)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if (stack_a->p2 > node->data)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}
