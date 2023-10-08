/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:28 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/08 16:56:37 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks --list push_swap");
}

t_node	*get_node(int data);
t_node	*search(t_node *node, int data);

void	insert(t_node *node, int data)
{
	t_node	*new_node;

	new_node = get_node(data);
	new_node->prev = node;
	new_node->next = node->next;
	node->next->prev = new_node;
	node->next = new_node;
}

void	delete(t_node *node, int data)
{
	node = search(node, data);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}

t_node	*search(t_node *node, int data)
{
	node = node->next;

	while (node->next)
	{
		if (node->data == data)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_node	*get_node(int data)
{
	t_node	*node;
	int		tmp;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	init(t_node **head, t_node **tail)
{
	*head = get_node(0);
	*tail = get_node(0);
	if (*head == NULL || *tail == NULL)
		return (-1);
	(*head)->next = *tail;
	(*tail)->prev = *head;
	return (1);
}

int main(int argc, char **argv)
{
	t_node	*head;
	t_node	*tail;
	t_node	*node;

	if (init(&head, &tail) < 0)
		return (-1);
	for (int i = 1 ;i < 5 ; i++)
		insert(head, i);

	
	node = head->next;
	while(node->next)
	{
		ft_printf("%d ", node->data);
		node = node->next;
	}
	(void)argv;
	atexit(check_leaks);
	return (0);
}