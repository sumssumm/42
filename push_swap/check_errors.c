#include "push_swap.h"

int	check_asceding(t_stack *stack)
{
	t_node	*node;

	node = stack->head->next;
	while(node != stack->tail)
	{
		if (node->data > node->next->data)
			return (-1);
		node = node->next;
	}
	return (0);
}

int	check_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (-1);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ps_atoi(argv[i]) == ps_atoi(argv[j]))
				print_error (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(int argc, char **argv)
{
	if (check_number(argc, argv) == -1)
		print_error(-1);
	if (check_double(argc, argv) == -1)
		print_error(-1);
	return (0);
}