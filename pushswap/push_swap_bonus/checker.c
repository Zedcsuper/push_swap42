/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:18:08 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/07 17:13:16 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"

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

void	exec_instruction(t_stack **pile_a, t_stack **pile_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		do_sa(pile_a);
	else if (!ft_strcmp(instruction, "sb\n"))
		do_sb(pile_b);
	else if (!ft_strcmp(instruction, "ss\n"))
		do_ss(pile_a, pile_b);
	else if (!ft_strcmp(instruction, "ra\n"))
		do_ra(pile_a);
	else if (!ft_strcmp(instruction, "rb\n"))
		do_rb(pile_b);
	else if (!ft_strcmp(instruction, "rr\n"))
		do_rr(pile_a, pile_b);
	else if (!ft_strcmp(instruction, "rra\n"))
		do_rra(pile_a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		do_rrb(pile_b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		do_rrr(pile_a, pile_b);
	else if (!ft_strcmp(instruction, "pa\n"))
		do_pa(pile_a, pile_b);
	else if (!ft_strcmp(instruction, "pb\n"))
		do_pb(pile_a, pile_b);
	else
		exit_error(pile_a, pile_b);
}

void	read_from_stdin(t_stack **pile_a, t_stack **pile_b)
{
	char		*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		exec_instruction(pile_a, pile_b, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (is_sorted (*pile_a) && get_stack_size(*pile_b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("K0\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_size = get_stack_size(stack_a);
	read_from_stdin(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
