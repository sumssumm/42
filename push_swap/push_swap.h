/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:17:57 by suminpar          #+#    #+#             */
/*   Updated: 2023/11/01 16:47:42 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		p1;
	int		p2;
	int		a_pos;
	int		b_pos;
}	t_stack;

void	push(t_stack *stack, int data);
int		pop(t_stack *stack);
t_node	*get_node(int data);
void	init_stack(t_stack **stack);
int		stack_size(t_stack *stack);
void	av_to_stack(int argc, char **argv, t_stack *stack, int *arr);

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	ft_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	find_min_max(t_stack *stack, int *min, int *max);
void	sort_stack_b(t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	final_sort(t_stack *stack_a);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack_a, t_stack *stack_b);
void	count_rotate(t_stack *stack_a, t_stack *stack_b);
int		count_pos(t_stack *stack_a, int b_data, int pos);

void	check_errors(int argc, char **argv);
void	check_number(int argc, char **argv);
void	check_double(int argc, char **argv);
int		check_asceding(t_stack *stack);

int		ps_atoi(char *str);
void	print_error(void);
void	ft_sort_int_tab(int *tab, int size, t_stack *stack_a);
void	get_pivot(int size, int *num_arr, t_stack *stack);
int		abs(int num);

void	excute_rr_rrr(t_stack *stack_a, t_stack *stack_b);
void	excute_ra_rra(t_stack *stack_a);
void	excute_rb_rrb(t_stack *stack_b);

void	check_argv(int argc, char **argv);
char	*join_argv(int argc, char **argv);
char	**split_argv(char *str, int *size);
char	*dup_argv(char **argv);

void	split_free(char **split);
void	stack_free(t_stack *stack);
void	all_stack_free(t_stack *a, t_stack *b);

#endif