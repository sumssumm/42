/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:19:43 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 17:29:15 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}

void	all_stack_free(t_stack *a, t_stack *b)
{
	stack_free(a);
	stack_free(b);
}
