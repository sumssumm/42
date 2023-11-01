/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:44:12 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 18:27:27 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size, t_stack *stack_a)
{
	int	i;
	int	j;
	int	tmp;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
	get_pivot(size, tab, stack_a);
}

int	abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char	*dup_argv(char **argv)
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
	str = dup_argv(argv);
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

char	**split_argv(char *str, int *size)
{
	int		i;
	char	**str_split;

	i = 0;
	*size = 0;
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
