/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:50:36 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/05 15:36:55 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

int		get_lowest_index_position(t_stack **stack);
int		get_stack_size(t_stack *stack);
int		is_correct_input(char **av);
int		is_digit(char c);
int		is_sign(char c);
int		is_sorted(t_stack *stack);
int		nb_abs(int nb);
int		nbstr_cmp(const char *s1, const char *s2);
//long	ft_atoi(const char *str);
t_stack	*fill_stack_values(int ac, char **av);
t_stack	*get_stack_before_bottom(t_stack *stack);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack **stack, t_stack *new_node);
void	assign_index(t_stack *stack_a, int ac);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	do_pa(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);
void	do_ra(t_stack **a);
void	do_rb(t_stack **b);
void	do_rr(t_stack **a, t_stack **b);
void	do_rra(t_stack **a);
void	do_rrb(t_stack **b);
void	do_rrr(t_stack **a, t_stack **b);
void	do_sa(t_stack **a);
void	do_ss(t_stack **a, t_stack **b);
void	do_sb(t_stack **b);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);
void	ft_putstr(char *str);
void	get_cost(t_stack **a, t_stack **b);
void	get_target_position(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	tiny_sort(t_stack **stack);

#endif
