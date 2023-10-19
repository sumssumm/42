#include "push_swap.h"

// void	delete(t_node *node, int data)
// {
// 	node = search(node, data);
// 	node->prev->next = node->next;
// 	node->next->prev = node->prev;
// 	free(node);
// }

// t_node	*search(t_node *node, int data)
// {
// 	node = node->next;

// 	while (node->next)
// 	{
// 		if (node->data == data)
// 			return (node);
// 		node = node->next;
// 	}
// 	return (NULL);
// }

int	push(t_stack *stack, int data)  // 스택에 요소를 푸시하는 함수
{
	t_node	*node;
	
	node = get_node(data);
	if (node == NULL)
		return (-1);
	node->next = stack->head->next;
	node->prev = stack->head;
	stack->head->next = node;
	node->next->prev = node;
	return (1);
}

int	pop(t_stack *stack) // 스택에서 요소를 팝하는 함수
{
	t_node	*tmp;
	int		data;

	if (stack->head->next == stack->tail)
	{
		ft_printf("empty stack\n");
		return (-1);
	}
	tmp = stack->head->next;
	data = tmp->data;
	stack->head->next = tmp->next;
	tmp->next->prev = stack->head;
	free(tmp);
	return (data);
}

int	peek(t_stack *stack) // 스택 상단 요소를 반환하는 함수(팝하지 않고)
{
	if (stack->head->next == stack->tail)
	{
		ft_printf("empty stack\n");
		return (-1);
	}
	return (stack->head->next->data);
}

t_node	*get_node(int data)  // 새로운 노드를 생성하고 값을 설정
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	init_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (*stack == NULL)
		return (-1);
	(*stack)->head = get_node(0);
	(*stack)->tail = get_node(0);
	if ((*stack)->head == NULL || (*stack)->tail == NULL)
		return (-1);
	(*stack)->head->next = (*stack)->tail;
	(*stack)->tail->prev = (*stack)->head;
	return (1);
}
