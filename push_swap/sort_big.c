#include "push_swap.h"

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	count_pos(t_stack *stack_a, int b_data)
{
	int		a_min;
	int		a_max;
	int		num;
	int		pos;
	t_node	*node;

	pos = 0;
	node = stack_a->head->next;
	find_min_max(stack_a, &a_min, &a_max);
	while (node != stack_a->tail)
	{
		num = node->data;
		if (b_data < a_min)
		{
			if (num == a_min)
				break ;
		}
		else if (b_data > a_max)
		{
			if (num == a_max)
			{
				pos++;
				break ;
			}
		}
		else
		{
			if (node->next != stack_a->tail && b_data > node->data && (b_data < node->next->data))
			{
				pos++;
				break ;
			}
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
		a_cnt = count_pos(stack_a, b_data);
		b_cnt = pos;
		if (pos > stack_size(stack_b) / 2)
			b_cnt = pos - stack_size(stack_b);
		if (pos == 0
			|| abs(stack_a->a_pos) + abs(stack_b->b_pos) > abs(a_cnt) + abs(b_cnt))
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
	while (pos)
	{
		if (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
		else
		{
			rra(stack_a);
			pos++;
		}
	}
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