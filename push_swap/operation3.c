#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*before_last;
	t_node	*top;

	last = stack_a->tail->prev;
	before_last = last->prev;
	top = stack_a->head->next;
	if (top != stack_a->tail && top->next != stack_a->tail)
	{
		before_last->next = stack_a->tail;
		stack_a->tail->prev = before_last;
		stack_a->head->next = last;
		last->prev = stack_a->head;
		last->next = top;
		top->prev = last;
	}
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*before_last;
	t_node	*top;

	last = stack_b->tail->prev;
	before_last = last->prev;
	top = stack_b->head->next;
	if (top != stack_b->tail && top->next != stack_b->tail)
	{
		before_last->next = stack_b->tail;
		stack_b->tail->prev = before_last;
		stack_b->head->next = last;
		last->prev = stack_b->head;
		last->next = top;
		top->prev = last;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}