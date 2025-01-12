/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamaien <zjamaien@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:16:10 by zjamaien          #+#    #+#             */
/*   Updated: 2025/01/12 14:56:28 by zjamaien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_free_av(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(av[i]);
		i++;
	}
	free(av);
	av = NULL;
}


void	exit_error(t_stack **a, t_stack **b)
{
	if (!a || *a != NULL)
		free_stack(a);
	if (!b || *b != NULL)
		free_stack(b);
	write(2, "Error\n", 6);
	exit (1);
}

int	get_av_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}
