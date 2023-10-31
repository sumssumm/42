/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:28 by suminpar          #+#    #+#             */
/*   Updated: 2023/10/24 07:16:13 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks --list push_swap");
}

void	empty_argv(int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				flag = 1;
			j++;
		}
		if (flag == 0)
			print_error();
		i++;
	}
	
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) == 2)
		sort_two(stack_a);
	else if (stack_size(stack_a) == 3)
		sort_three(stack_a);
	else if (stack_size(stack_a) <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_size(stack_a) > 5)
		sort_big(stack_a, stack_b);
}

void	av_to_stack(int argc, char **argv, t_stack *stack, int *arr)
{
	int		i;
	int		data;

	i = argc - 1;
	while (i >= 0)
	{
		data = ps_atoi(argv[i]);
		arr[i - 1] = data;
		if (push(stack, data) < 0)
			print_error();
		i--;
	}
}

char	*first_argv_dup(char **argv)
{
	char	*str;

	str = ft_strdup(argv[1]);
	if (str == NULL)
		return (NULL);
	if (ft_strncmp(str, "", 1) == 0)
		print_error();
	return (str);
}

char	*join_argv(int argc, char **argv)
{
	char	*tmp;
	char	*str;
	int		i;

	i = 1;
	str = first_argv_dup(argv);
	if (str == NULL)
		return (NULL);
	while (i < argc - 1)
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		if (str == NULL)
			return (NULL);
		tmp = str;
		str = ft_strjoin(str, argv[i + 1]);
		free(tmp);
		if (str == NULL)
			return (NULL);
		i++;
	}
	return (str);
}

char	**split_in_num_arr(char *str, int *size)
{
	int		i;
	char	**str_split;

	i = 0;
	if (str == NULL)
		return (NULL);
	str_split = ft_split(str, ' ');
	free(str);
	if (str_split == NULL)
		return (NULL);
	while (str_split[i])
		i++;
	*size = i;
	return (str_split);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*num_arr;
	char	**str_split;
	int		size;

	if (argc < 2)
		return (-1);
	empty_argv(argc, argv);
	if (init_stack(&stack_a) < 0 || init_stack(&stack_b) < 0)
		return (-1);
	str_split = split_in_num_arr(join_argv(argc, argv), &size);
	check_errors(size, str_split);
	num_arr = (int *)malloc(sizeof(int) * (size));
	if (num_arr == NULL)
		return (-1);
	av_to_stack(size, str_split, stack_a, num_arr);
	ft_sort_int_tab(num_arr, size);
	get_pivot(size, num_arr, stack_a);
	if (check_asceding(stack_a) == -1)
		ft_sort(stack_a, stack_b);
	// free(stack_a);
	// atexit(check_leaks);
	exit(0);
	return (0);
}
