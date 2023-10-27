#include "push_swap.h"

void	sort_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	
	while (stack_size(stack_b))
	{
		pa(stack_a, stack_b);
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
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
	while (stack_size(stack_a) > 3)
		pb(stack_a, stack_b);
	if (stack_size(stack_a) == 3)
		sort_three(stack_a);
	if (stack_size(stack_a) == 2)
		sort_two(stack_a);
	sort_stack_b(stack_a, stack_b);
}