/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:40 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 17:15:36 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*node;

	node = get_node(data);
	if (node == NULL)
		exit(1);
	node->next = stack->head->next;
	node->prev = stack->head;
	stack->head->next = node;
	node->next->prev = node;
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		data;

	if (stack->head->next == stack->tail)
		return (-1);
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
		exit(1);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	init_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (*stack == NULL)
		exit(1);
	(*stack)->head = get_node(0);
	(*stack)->tail = get_node(0);
	if ((*stack)->head == NULL || (*stack)->tail == NULL)
		exit(1);
	(*stack)->head->next = (*stack)->tail;
	(*stack)->tail->prev = (*stack)->head;
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
