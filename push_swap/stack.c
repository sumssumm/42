/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:40 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/24 07:03:24 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack, int data)
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

int	pop(t_stack *stack)
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

t_node	*get_node(int data)
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
	(*stack)->size_a = 0;
	(*stack)->size_b = 0;
	return (1);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*node;

	node = stack->head->next;
	size = 0;
	while (node != stack->tail)
	{
		size++;
		node = node->next;
	}
	return (size);
}