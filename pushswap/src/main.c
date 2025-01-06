/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:38:02 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/06 18:51:43 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*a))
		do_sa(a);
	else if (stack_size == 3)
		tiny_sort(a);
	else if (stack_size > 3 && !is_sorted(*a))
		sort(a, b);
}

/*
static void	debug_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("\n");
}
*/

//void	init_stack(t_stack *stack_a, t_stack

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		is_one_str;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = get_av_len(av);
		if (ac == 0)
			ft_free_av(av, ac);
		is_one_str = 1;
	}	
	if (!is_correct_input(av))
	{
		if (is_one_str)
			ft_free_av(av, ac);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av, is_one_str);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (is_one_str)
		ft_free_av(av, ac);
	return (0);
}
