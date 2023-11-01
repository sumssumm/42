/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:52 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 18:24:00 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_asceding(t_stack *stack)
{
	t_node	*node;

	node = stack->head->next;
	while (node != stack->tail->prev)
	{
		if (node->data > node->next->data)
			return (-1);
		node = node->next;
	}
	return (0);
}

void	check_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			print_error();
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' ')
				j++;
			else if (argv[i][j] < '0' || argv[i][j] > '9')
				print_error();
			else
				j++;
		}
		i++;
	}
}

void	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ps_atoi(argv[i]) == ps_atoi(argv[j]))
				print_error ();
			j++;
		}
		i++;
	}
}

void	check_errors(int argc, char **argv)
{
	check_number(argc, argv);
	check_double(argc, argv);
}
