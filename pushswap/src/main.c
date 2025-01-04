/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:38:02 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/04 20:15:07 by zjamaien         ###   ########.fr       */
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

static void	debug_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	int *allav = malloc(sizeof(int) * (ac - 1));
	int x = 0;
	while (x < ac - 1)
	{
		allav[x] = ft_atoi(av[x + 1]);
		x++;
	}
	int j = 0;
	x = 0;
	while (x < ac - 1)
	{
		j = x + 1;
		while (j < ac - 1)
		{
			if (allav[x] == allav[j])
			{
				free(allav);
				ft_putstr("Error\n");
				return (0);
				//exit_error(NULL, NULL);
			}
			j++;
		}
		x++;
	}
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
//	debug_stack(stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
